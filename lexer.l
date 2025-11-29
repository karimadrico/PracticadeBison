%{
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
%}
%option noyywrap
%%
[ \t\r\n]+   { /* Ignorar */ ; }
/* Comentario COBOL (columna 7): seis espacios ASCII seguidos de '*' */
^[ ][ ][ ][ ][ ][ ]\*.*    { /* Ignorar línea completa de comentario COBOL */ ; }
/* Comentarios en línea: comienzan con "*>" o "*|" y van hasta el fin de línea */
*>[^\n]*    { /* Ignorar comentario que comienza con "*>" */ ; }
\*\|[^\n]*   { /* Ignorar comentario que comienza con "*|" */ ; }
[ \t\r\n]+   { /* Ignorar */ ; }
\"[^\"]*\"      { /* yylval.cad = strdup(yytext); */ return CAD; }
\'[^\']*\'      { /* yylval.cad = strdup(yytext); */ return CAD; }
PROGRAMA     { return PROGRAMA; }
INICIO       { return INICIO; }
FIN          { return FIN; }
DISPLAY      { return DISPLAY; }
LEE          { return LEE; }
SI           { return SI; }
ENTONCES     { return ENTONCES; }
SINO         { return SINO; }
MUESTRA      { return MUESTRA; }
MIENTRAS     { return MIENTRAS; }
HACER        { return HACER; }
FINMIENTRAS  { return FINMIENTRAS; }
[0-9]+       { return NUM; }
[A-Z][A-Z0-9-]* {
    int L = (int)strlen(yytext);
    if (L > 0 && (yytext[0]=='-' || yytext[L-1]=='-')) {
        /* Ignorar identificador inválido */
    } else {
        return ID;
    }
}
\\.            { return '.'; }
.             { return yytext[0]; }
%%
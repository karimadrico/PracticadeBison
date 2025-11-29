%{
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
%}
%option noyywrap
%%
"      *".*      { /* Ignorar línea completa de comentario COBOL */ ; }
"*>".*           { /* Ignorar comentario que comienza con "*>" */ ; }
"*|".*           { /* Ignorar comentario que comienza con "*|" */ ; }
[ \t\r\n]+   { /* Ignorar */ ; }
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
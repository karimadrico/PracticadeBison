%{
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
%}
%option noyywrap
%%
/* Comentario COBOL: exactamente 6 espacios y luego '*' */
^[ ]{6}\*.*      { /* Ignorar comentario de línea completa */ ; }

/* Comentarios en línea: '*>', '*|' */
*>.*        { /* Ignorar hasta fin de línea */ ; }
*|.*        { /* Ignorar hasta fin de línea */ ; }

/* Espacios y saltos de línea */
[ \t\r\n]+    { /* Ignorar */ ; }

/* Strings dobles y simples */
\"[^\"]*\"      { yylval.cad = strdup(yytext); return CAD; }
\'[^\']*\'      { yylval.cad = strdup(yytext); return CAD; }

/* Palabras reservadas */
PROGRAMA     { return PROGRAMA; }
INICIO       { return INICIO; }
FIN          { return FIN; }
LEE          { return LEE; }
MUESTRA      { return MOSTRAR; }
MOSTRAR      { return MOSTRAR; }
SI           { return SI; }
ENTONCES     { return ENTONCES; }
SINO         { return SINO; }
ES           { return ES; }
IGUAL        { return IGUAL; }
MAYOR        { return MAYOR; }
MENOR        { return MENOR; }
QUE          { return QUE; }
MIENTRAS     { return MIENTRAS; }
HACER        { return HACER; }
FINMIENTRAS  { return FINMIENTRAS; }
EJECUTA      { return EJECUTA; }
VECES        { return VECES; }
USANDO       { return USANDO; }
FIN-EJECUTA  { return FIN_EJECUTA; }
FINSI        { return FINSI; }
FIN-SI       { return FINSI; }
HASTA-QUE    { return HASTAQUE; }
SUMA         { return SUMA; }
RESTA        { return RESTA; }
MULTIPLICA   { return MULTIPLICA; }
DIVIDE       { return DIVIDE; }
DANDO        { return DANDO; }
CALCULA      { return CALCULA; }
FIN-CALCULA  { return FIN_CALCULA; }
MUEVE        { return MUEVE; }
A            { return A; }
DE           { return DE; }
COMO         { return COMO; }
POR          { return POR; }
","          { return ','; }

/* Números */
[0-9]+       { yylval.num = atoi(yytext); return NUM; }

/* Identificadores válidos: no empiezan/terminan por guion, no empiezan por dígito */
[A-Z]([A-Z0-9]*(-[A-Z0-9]+)*)   { yylval.id = strdup(yytext); return ID; }

\.            { return '.'; }
.             { return yytext[0]; }
%%
#ifdef TEST_LEXER
int main(void) {
    int token;
    while ((token = yylex()) != 0) {
        printf("TOKEN: %d (%s)\n", token, yytext);
    }
    return 0;
}
#endif
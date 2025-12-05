%{
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
%}
%option noyywrap
%%
/* Ignorar cualquier línea que empiece por espacios opcionales y '*' (cubre columna-7) */
^[ \t]*\*.*      { /* Ignorar comentario de línea completa */ ; }

/* Comentario en línea que empieza por '*>'. ('*|' es trampa y se omite) */
"*>".*        { /* Ignorar hasta fin de línea */ ; }

/* Espacios y saltos de línea */
[ \t\r\n]+    { /* Ignorar */ ; }
\"[^\"]*\"      { yylval.cad = strdup(yytext); return CAD; }
\'[^\']*\'      { yylval.cad = strdup(yytext); return CAD; }
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
"FIN-SI"     { return FINSI; }
"HASTA-QUE"  { return HASTAQUE; }
SUMA         { return SUMA; }
RESTA        { return RESTA; }
MULTIPLICA   { return MULTIPLICA; }
DIVIDE       { return DIVIDE; }
DANDO        { return DANDO; }
CALCULA      { return CALCULA; }
"FIN-CALCULA" { return FIN_CALCULA; }
MUEVE        { return MUEVE; }
A            { return A; }
DE           { return DE; }
COMO         { return COMO; }
POR          { return POR; }
","          { return ','; }
[0-9]+       { yylval.num = atoi(yytext); return NUM; }
[A-Z][A-Z0-9-]*    { yylval.id = strdup(yytext); return ID; }
\.            { return '.'; }
.             { return yytext[0]; }
%%
// Helper para pruebas del lexer si se compila con -DTEST_LEXER
#ifdef TEST_LEXER
int main(void) {
    int token;
    while ((token = yylex()) != 0) {
        printf("TOKEN: %d (%s)\n", token, yytext);
    }
    return 0;
}
#endif
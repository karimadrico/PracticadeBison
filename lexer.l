%{
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
%}
%option noyywrap
%%
"      *".*      { /* Ignorar línea completa de comentario COBOL */ ; }
"*>".*         { /* Ignorar comentario en línea iniciando con '*>'. */ ; }
"*|".*         { /* Ignorar comentario en línea iniciando con '*|' */ ; }
[ \t\r\n]+   { /* Ignorar espacios y saltos de línea */ ; }
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
MIENTRAS     { return MIENTRAS; }
HACER        { return HACER; }
FINMIENTRAS  { return FINMIENTRAS; }
EJECUTA      { return EJECUTA; }
VECES        { return VECES; }
USANDO       { return USANDO; }
FIN-EJECUTA  { return FIN_EJECUTA; }
FINSI        { return FINSI; }
"FIN-SI"     { return FINSI; }
SUMA         { return SUMA; }
RESTA        { return RESTA; }
MULTIPLICA   { return MULTIPLICA; }
DIVIDE       { return DIVIDE; }
DANDO        { return DANDO; }
[0-9]+       { yylval.num = atoi(yytext); return NUM; }
[A-Z]([A-Z0-9\-]*)? {
    int L = (int)strlen(yytext);
    /* Prohibir identificadores que empiezan o terminan con '-' */
    if (yytext[0] == '-' || yytext[L-1] == '-') {
        /* Identificador inválido: ignorar o reportar error */
        fprintf(stderr, "Identificador inválido: %s\n", yytext);
        ;
    } else {
        yylval.id = strdup(yytext);
        return ID;
    }
}
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
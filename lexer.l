%{
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
%}
%option noyywrap
%%
"      *".*      { /* Ignorar línea completa de comentario COBOL */ ; }
("*>".*|"*|".*)   { /* Ignorar comentario en línea */ ; }
[ \t\r\n]+   { /* Ignorar */ ; }
\"[^\"]*\"      { yylval.cad = strdup(yytext); return CAD; }
\'[^\']*\'      { yylval.cad = strdup(yytext); return CAD; }
PROGRAMA     { return PROGRAMA; }      // Inicio de programa
INICIO       { return INICIO; }        // Inicio de bloque principal
FIN          { return FIN; }           // Fin de programa
LEE          { return LEE; }           // Leer valor
MUESTRA      { return MUESTRA; }       // Mostrar valor
SI           { return SI; }            // Condicional
ENTONCES     { return ENTONCES; }      // Rama verdadera
SINO         { return SINO; }          // Rama falsa
MIENTRAS     { return MIENTRAS; }      // Bucle tipo while
HACER        { return HACER; }         // Inicio de bloque de bucle
FINMIENTRAS  { return FINMIENTRAS; }   // Fin de bucle while
SUMA         { return SUMA; }          // Suma aritmética
RESTA        { return RESTA; }         // Resta aritmética
MULTIPLICA   { return MULTIPLICA; }    // Multiplicación aritmética
DIVIDE       { return DIVIDE; }        // División aritmética
DANDO        { return DANDO; }         // Clausula DANDO
[0-9]+       { yylval.num = atoi(yytext); return NUM; }
[A-Z]([A-Z0-9]*(-[A-Z0-9]+)*)? {
    int L = (int)strlen(yytext);
    // Lista de palabras reservadas
    const char *reservadas[] = {
        "PROGRAMA", "INICIO", "FIN", "DISPLAY", "LEE", "SI", "ENTONCES", "SINO", "MUESTRA", "MIENTRAS", "HACER", "FINMIENTRAS",
        "SUMA", "RESTA", "MULTIPLICA", "DIVIDE", "DANDO"
    };
    int es_reservada = 0;
    for (int i = 0; i < sizeof(reservadas)/sizeof(reservadas[0]); ++i) {
        if (strcmp(yytext, reservadas[i]) == 0) {
            es_reservada = 1;
            break;
        }
    }
    if (L > 0 && (yytext[0]=='-' || yytext[L-1]=='-' || es_reservada)) {
        /* Ignorar identificador inválido o reservado */
    } else {
        yylval.id = strdup(yytext); return ID;
    }
}
\.            { return '.'; }
.             { return yytext[0]; }
%%
// Necesario main de prueba para ver la salida de los tokens cuando compilo con -DTEST_LEXER
#ifdef TEST_LEXER
int main(void) {
    int token;
    while ((token = yylex()) != 0) {
        printf("TOKEN: %d (%s)\\n", token, yytext);
    }
    return 0;
}
#endif
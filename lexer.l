%{
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
    
int keyword_or_id(void) {
	if (strcmp(yytext, "PROGRAMA") == 0) return PROGRAMA;
	if (strcmp(yytext, "INICIO") == 0) return INICIO;
	if (strcmp(yytext, "FIN") == 0) return FIN;
	if (strcmp(yytext, "MIENTRAS") == 0) return MIENTRAS;
	if (strcmp(yytext, "HACER") == 0) return HACER;
	if (strcmp(yytext, "FINMIENTRAS") == 0) return FINMIENTRAS;
	if (strcmp(yytext, "SI") == 0) return SI;
	if (strcmp(yytext, "ENTONCES") == 0) return ENTONCES;
	if (strcmp(yytext, "FINSI") == 0) return FINSI;
	if (strcmp(yytext, "LEER") == 0) return LEER;
	if (strcmp(yytext, "MOSTRAR") == 0) return MOSTRAR;
	return ID;
}

%}

%option noyywrap

%%

/* Números */
[0-9]+            { return NUM; }

/* Identificadores y palabras reservadas (mayúsculas) */
[A-Z][A-Z0-9-]*   { return keyword_or_id(); }

\.                { return '.'; }

/* Espacios en blanco */
[ \t\r\n]+      { /* Ignorar espacios en blanco */ }

/* Comentario COBOL: línea que empieza por 6 espacios y un asterisco */
"      *".*        { /* Ignorar línea completa de comentario COBOL */ }

/* Comentario de línea: desde *> o *| hasta el final de la línea */
"*>".*            { /* Ignorar comentario que comienza con "*>" */ }
"*|".*            { /* Ignorar comentario que comienza con "*|" */ }

/* Cadenas de caracteres: dobles y simples (no permiten comillas desbalanceadas) */
"[^"]*"          { return CAD; }
'[^']*'            { return CAD; }

/* Cualquier otro carácter (operadores, puntuación) */
.                 { return yytext[0]; }

%%

int yywrap(void) { return 1; }
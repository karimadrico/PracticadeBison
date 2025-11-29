%{
#include "parser.tab.h"
#include <stdio.h>
%}

%option noyywrap

%%

/* Palabras reservadas COBOL */
"PROGRAMA"       { return PROGRAMA; }
"INICIO"         { return INICIO; }
"FIN"            { return FIN; }
"MIENTRAS"       { return MIENTRAS; }
"HACER"          { return HACER; }
"FINMIENTRAS"    { return FINMIENTRAS; }
"SI"             { return SI; }
"ENTONCES"       { return ENTONCES; }
"FINSI"          { return FINSI; }
"LEER"           { return LEER; }
"MOSTRAR"        { return MOSTRAR; }

/* Números e identificadores */
[0-9]+            { return NUM; }
[A-Z][A-Z0-9-]*   { return ID; }

"."              { return '.'; }

/* Espacios en blanco */
[ \t\r\n]+      { /* ignorar espacios en blanco */ }

/* Comentarios en linea hasta el final de la linea: "*>" o "*|" */
\*>.*             { /* ignorar comentario que empieza con "*>" */ }
\*\|.*           { /* ignorar comentario que empieza con "*|" */ }

/* Cualquier otro carácter (operadores, puntuación) */
.                 { return yytext[0]; }

%%

int yywrap(void) { return 1; }
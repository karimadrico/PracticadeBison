%{
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

%}

%option noyywrap

%%

/* Comentario COBOL: línea que empieza por 6 espacios y un asterisco */
^[ ][ ][ ][ ][ ][ ]\*.*          { /* Ignorar línea completa de comentario COBOL */ ; }

/* Comentarios en línea: *> o *| hasta fin de línea */
\*>[^\n]*           { /* Ignorar comentario que comienza con "*>" */ ; }
\*\|[^\n]*         { /* Ignorar comentario que comienza con "*|" */ ; }

/* Espacios en blanco */
[ \t\r\n]+         { /* Ignorar espacios en blanco */ ; }

/* Cadenas entre comillas dobles o simples */
\"[^\"]*\"            { return CAD; }
\'[^\']*\'         { return CAD; }

/* Números */
[0-9]+               { return NUM; }

/* Palabras reservadas (mayúsculas exactas) */
PROGRAMA             { return PROGRAMA; }
INICIO               { return INICIO; }
FIN                  { return FIN; }
MIENTRAS             { return MIENTRAS; }
HACER                { return HACER; }
FINMIENTRAS          { return FINMIENTRAS; }
SI                   { return SI; }
ENTONCES             { return ENTONCES; }
FINSI                { return FINSI; }
LEER                 { return LEER; }
MOSTRAR              { return MOSTRAR; }

/* Identificador general: comienza por letra mayúscula y puede contener dígitos y guiones */
[A-Z][A-Z0-9-]*      { return ID; }

/* Punto como token literal */
\.                   { return '.'; }

/* Cualquier otro caracter */
.                    { return yytext[0]; }

%%

int yywrap(void) { return 1; }
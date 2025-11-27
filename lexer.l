%{
#include "parser.tab.h"
#include <stdio.h>
%}

%%
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
[0-9]+            { return NUM; }
[A-Z][A-Z0-9-]*   { return ID; }
\.                { return '.'; }
[ \t\r\n]+      { /* ignore whitespace */ }

/* Comentario COBOL: línea que empieza por 6 espacios y asterisco */
^      \*.*        { /* ignore full COBOL comment line */ }

/* Comentario de línea: desde *> o *| hasta fin de línea */
\*>[^\n]*          { /* ignore comment starting with "*>" */ }
\*\|[^\n]*        { /* ignore comment starting with "*|" */ }

.                 { return yytext[0]; }

%%

int yywrap(void) { return 1; }
%{
#include "parser.tab.h"
#include <stdio.h>
%}
%%
"PROGRAMA"   { return PROGRAMA; }
"INICIO"     { return INICIO; }
"FIN"        { return FIN; }
"MIENTRAS"   { return MIENTRAS; }
"HACER"      { return HACER; }
"FINMIENTRAS" { return FINMIENTRAS; }
"SI"         { return SI; }
"ENTONCES"   { return ENTONCES; }
"FINSI"      { return FINSI; }
"LEER"       { return LEER; }
"MOSTRAR"    { return MOSTRAR; }
[0-9]+       { return NUM; }
[A-Z][A-Z0-9-]* { return ID; }
\.           { return '.'; }
[ \t\r\n]+  { /* ignorar espacios */ }

/* Comentario COBOL: línea que empieza por 6 espacios y asterisco */
"      *".*   { /* ignorar línea completa COBOL */ }

/* Comentario de línea: desde *> o *| hasta fin de línea */
"*>".*         { /* ignorar comentario de línea */ }
"*|".*         { /* ignorar comentario de línea */ }
.		 { return yytext[0]; }
%%

int yywrap(void) { return 1; }
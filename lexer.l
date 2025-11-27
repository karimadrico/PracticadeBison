%{
#include "parser.tab.h"
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
[ \t\n]+     { /* ignorar espacios */ }

/* Comentario COBOL: línea que empieza por 6 espacios y asterisco */
	\*.*      { /* ignorar línea completa COBOL */ }

/* Comentario de línea: desde *> o *| hasta fin de línea */
\*\>.*          { /* ignorar comentario de línea */ }
\*\|.*          { /* ignorar comentario de línea */ }
%%
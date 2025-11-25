%{
#include "parser.tab.h"
%}
%%
"PROGRAMA"   { return PROGRAMA; }
"INICIO"     { return INICIO; }
"FIN"        { return FIN; }
[A-Z][A-Z0-9-]* { return ID; }
\.           { return '.'; }
[ \t\n]+     { /* ignorar espacios */ }
%%
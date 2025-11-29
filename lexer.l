%{
#include <stdio.h>
// Cabecera para tokens y funciones de cadena
#include "parser.tab.h"
#include <string.h>
%}
%option noyywrap
%%
[ \t\r\n]+   { /* Ignorar */ ; }
.             { return yytext[0]; }
// Palabras clave (mayúsculas, antes que ID)
PROGRAMA     { return PROGRAMA; }
INICIO       { return INICIO; }
FIN          { return FIN; }
DISPLAY      { return DISPLAY; }
LEE          { return LEE; }
SI           { return SI; }
ENTONCES     { return ENTONCES; }
SINO         { return SINO; }
MUESTRA      { return MUESTRA; }
MIENTRAS     { return MIENTRAS; }
HACER        { return HACER; }
FINMIENTRAS  { return FINMIENTRAS; }
.             { return yytext[0]; }
%%

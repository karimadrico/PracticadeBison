%{
#include <stdio.h>
// Cabecera para tokens y funciones de cadena
#include "parser.tab.h"
#include <string.h>
%}
%option noyywrap
%%
[ \t\r\n]+   { /* Ignorar */ ; }
// Números positivos
[0-9]+       { /* yylval.num = atoi(yytext); */ return NUM; }

// Identificadores: letra mayúscula, dígitos y guiones, sin guión al inicio/fin
[A-Z][A-Z0-9-]* {
	int L = (int)strlen(yytext);
	if (L > 0 && (yytext[0]=='-' || yytext[L-1]=='-')) {
		/* Ignorar identificador inválido */
	} else {
		/* yylval.id = strdup(yytext); */ return ID;
	}
}
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

%{
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
%}
%option noyywrap
%%

^[ \t]*\*.*         { /* Comentario COBOL (tolerante) */ }
"*>".*              { /* Comentario en línea */ }
"*|".*              { /* Comentario en línea alternativa */ }
[ \t\r\n]+           { /* Espacios y saltos de línea */ }
"\""[^"]*"\""      { yylval.cad = strdup(yytext); return CAD; }
'[^']*'              { yylval.cad = strdup(yytext); return CAD; }

"PROGRAMA"          { return PROGRAMA; }
"INICIO"            { return INICIO; }
"FIN"               { return FIN; }
"LEE"               { return LEE; }
"MUESTRA"           { return MOSTRAR; }
"MOSTRAR"           { return MOSTRAR; }
"SI"                { return SI; }
"ENTONCES"          { return ENTONCES; }
"SINO"              { return SINO; }
"ES"                { return ES; }
"IGUAL"             { return IGUAL; }
"MAYOR"             { return MAYOR; }
"MENOR"             { return MENOR; }
"QUE"               { return QUE; }
"MIENTRAS"          { return MIENTRAS; }
"HACER"             { return HACER; }
"FINMIENTRAS"       { return FINMIENTRAS; }
"EJECUTA"           { return EJECUTA; }
"VECES"             { return VECES; }
"USANDO"            { return USANDO; }
"FIN-EJECUTA"       { return FIN_EJECUTA; }
"FINSI"             { return FINSI; }
"FIN-SI"            { return FINSI; }
"HASTA-QUE"         { return HASTAQUE; }
"SUMA"              { return SUMA; }
"RESTA"             { return RESTA; }
"MULTIPLICA"        { return MULTIPLICA; }
"DIVIDE"            { return DIVIDE; }
"DANDO"             { return DANDO; }
"CALCULA"           { return CALCULA; }
"FIN-CALCULA"       { return FIN_CALCULA; }
"MUEVE"             { return MUEVE; }
"A"                 { return A; }
"DE"                { return DE; }
"COMO"              { return COMO; }
"POR"               { return POR; }
","                { return ','; }

[0-9]+               { yylval.num = atoi(yytext); return NUM; }
[A-Z]([A-Z0-9-])*    {
	int L = (int)strlen(yytext);
	const char *reservadas[] = {
		"PROGRAMA","INICIO","FIN","LEE","MUESTRA","MOSTRAR","SI","ENTONCES","SINO","ES","IGUAL","MAYOR","MENOR","QUE","MIENTRAS","HACER","FINMIENTRAS","EJECUTA","VECES","USANDO","FIN-EJECUTA","FINSI","HASTA-QUE","SUMA","RESTA","MULTIPLICA","DIVIDE","DANDO","CALCULA","FIN-CALCULA","MUEVE","A","DE","COMO","POR"
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
		return 0;
	} else {
		yylval.id = strdup(yytext);
		return ID;
	}
}
\.                   { return '.'; }
.                    { return yytext[0]; }
%%
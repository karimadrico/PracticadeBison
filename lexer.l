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

/* COBOL: comentario en columna 7 (seis espacios ASCII seguidos de '*') */
^[ ][ ][ ][ ][ ][ ]\*.*    { /* Ignorar */ }

/* Comentarios en línea: comienzan con "*>" o "*|" hasta fin de línea */
\*>[^\n]*    { /* Ignorar */ }
\*\|[^\n]*   { /* Ignorar */ }

/* Espacios en blanco */
[ \t\r\n]+   { /* Ignorar */ }

/* Cadenas (sin saltos de línea) */
\"[^\"\n]*\"   { return CAD; }
'[^'\n]*'          { return CAD; }

/* Números */
[0-9]+       { return NUM; }

/* Palabras reservadas (mayúsculas) - colocadas antes de la regla ID */
PROGRAMA     { return PROGRAMA; }
INICIO       { return INICIO; }
FIN          { return FIN; }
MIENTRAS     { return MIENTRAS; }
HACER        { return HACER; }
FINMIENTRAS  { return FINMIENTRAS; }
SI           { return SI; }
ENTONCES     { return ENTONCES; }
FINSI        { return FINSI; }
LEER         { return LEER; }
MOSTRAR      { return MOSTRAR; }

/* Identificador */
[A-Z][A-Z0-9-]*  {
	int L = (int)strlen(yytext);
	if (L > 0 && (yytext[0]=='-' || yytext[L-1]=='-')) {
		fprintf(stderr,"Identificador inválido: %s\n", yytext);
		/* Ignorar */
	} else {
		return ID;
	}
}

/* Punto literal */
\.            { return '.'; }

/* Cualquier otro carácter */
.             { return yytext[0]; }

%%

int yywrap(void) { return 1; }
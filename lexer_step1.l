

%{
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

%}

%option noyywrap

%%

/* Comentario COBOL (columna 7): seis espacios ASCII seguidos de '*' */
^[ ][ ][ ][ ][ ][ ]\*.*    { /* Ignorar línea completa de comentario COBOL */ ; }

/* Comentarios en línea: comienzan con "*>" o "*|" y van hasta el fin de línea */
*>[^\n]*    { /* Ignorar comentario que comienza con "*>" */ ; }
\*\|[^\n]*   { /* Ignorar comentario que comienza con "*|" */ ; }

/* Espacios en blanco (incluye saltos de línea) */
[ \t\r\n]+   { /* Ignorar */ ; }

/* Cadenas: dobles o simples (sin salto de línea dentro) */
\"[^\"\n]*\"   { return CAD; }
'[^'\n]*'          { return CAD; }

/* Números positivos */
[0-9]+       { return NUM; }

/* Palabras reservadas (mayúsculas). Deben ir antes de ID. */
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

/* Identificador: empieza con letra mayúscula, puede contener dígitos y guiones
   validación en la acción para evitar guiones al inicio/fin */
[A-Z][A-Z0-9-]*  {
	int L = (int)strlen(yytext);
	if (L > 0 && (yytext[0]=='-' || yytext[L-1]=='-')) {
		fprintf(stderr,"Identificador inválido: %s\n", yytext);
		/* Ignorar token inválido */
	} else {
		return ID;
	}
}

/* Punto literal */
\.            { return '.'; }

/* Cualquier otro carácter: devolver su código ASCII */
.             { return yytext[0]; }

%%

int yywrap(void) { return 1; }
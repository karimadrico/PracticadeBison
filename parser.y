/* parser.y */
/* Práctica de Bison - Compilador COBOL simplificado */
/* Autor: Karima Drafli Rico */
%%
programa
  : PROGRAMA ID '.' INICIO sentencias FIN '.' /* aqui termina el programa */
%%
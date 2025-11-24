/* parser.y */
/* Práctica de Bison - Compilador COBOL simplificado */
/* Autor: Karima Drafli Rico */
%%
programa
  : PROGRAMA ID '.' /* aqui va el punto despues del nombre, falta mas cosas */
%%
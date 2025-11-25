/* parser.y */
/* Práctica de Bison - Compilador COBOL simplificado */
/* Autor: Karima Drafli Rico */
%%
programa
  : PROGRAMA ID '.' INICIO sentencias FIN '.' /* aqui termina el programa */
  
sentencias
  : sentencia /* una sola sentencia */
  | sentencias sentencia /* varias sentencias */
  | /* puede no haber sentencias, por si acaso */

sentencia
  : bucle /* esto es para los bucles, luego añado mas opciones */
  | comparar /* esto es para los condicionales, if y eso */
  | /* aqui va una sentencia */
%%
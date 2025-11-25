/* parser.y */
/* Práctica de Bison - Compilador COBOL simplificado */
/* Autor: Karima Drafli Rico */
%%
programa
  : PROGRAMA ID '.' INICIO sentencias FIN '.' /* aqui termina el programa */
  
sentencias
  : sentencia /* una sola sentencia */
  | sentencias sentencia /* varias sentencias */
  | /* puede no haber sentencias */

sentencia
  : bucle /* esto es para los bucles */
  | comparar /* esto es para los condicionales, if */
  | asignar /* esto es para las asignaciones y operaciones */
  | /* aqui va una sentencia */
%%
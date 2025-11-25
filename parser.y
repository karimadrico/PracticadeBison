/* parser.y */
/* Práctica de Bison - Compilador COBOL simplificado */
/* Autor: Karima Drafli Rico */
%token PROGRAMA INICIO FIN ID
%token '.' /* tratar el punto como token */
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
  | io /* esto es para entrada y salida, leer y mostrar */
  | /* aqui va una sentencia */

bucle
  : MIENTRAS condicion HACER sentencias FINMIENTRAS '.' /* estructura básica de bucle */
  | /* aquí iran otros tipos de bucle */

comparar
  : SI condicion ENTONCES sentencias FINSI '.' /* estructura básica de condicional */
  | /* aquí podrían ir variantes de condicional */

asignar
  : /* aqui van las asignaciones y operaciones */

io
  : /* aqui va la entrada y salida, leer y mostrar */
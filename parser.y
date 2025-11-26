/* parser.y */
/* Práctica de Bison - Compilador COBOL simplificado */
/* Autor: Karima Drafli Rico */
%{
#include <stdio.h>
extern FILE *yyin;
%}
%token PROGRAMA INICIO FIN ID
%token NUM MIENTRAS HACER FINMIENTRAS SI ENTONCES FINSI LEER MOSTRAR
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
  : ID '=' expresion '.' /* asignación simple */
  | /* aquí podrían ir otras formas de asignación */

io
  : LEER ID '.' /* lectura de variable */
  | MOSTRAR expresion '.' /* mostrar resultado */
  | /* aquí podrían ir otras formas de entrada/salida */

expresion
  : ID /* variable */
  | NUM /* número */
  | expresion '+' expresion /* suma */
  | expresion '-' expresion /* resta */
  | /* aquí irán más operaciones */

condicion
  : expresion '<' expresion /* menor que */
  | expresion '>' expresion /* mayor que */
  | expresion '=' expresion /* igual */
  | /* aquí podrían ir más comparaciones */
%%
void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}
int main(int argc, char *argv[]) {
  if (argc > 1) {
    FILE *f = fopen(argv[1], "r");
    if (!f) {
      perror("No se pudo abrir el archivo");
      return 1;
    }
    yyin = f;
  }
  yyparse();
  return 0;
}
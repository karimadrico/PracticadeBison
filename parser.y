/* parser.y */
/* Práctica de Bison - Compilador COBOL simplificado */
/* Autor: Karima Drafli Rico */
%{
#include <stdio.h>
extern FILE *yyin;
int yylex(void);
void yyerror(const char *s);
%}
%token PROGRAMA INICIO FIN ID
%token NUM CAD MIENTRAS HACER FINMIENTRAS SI ENTONCES FINSI LEE MOSTRAR
%token DISPLAY SINO MUESTRA
%token '.' /* tratar el punto como token */
%%
programa
  : PROGRAMA ID '.' INICIO sentencias FIN '.' /* aqui termina el programa */
  
sentencias
  : sentencia /* una sola sentencia */
  | sentencias sentencia /* varias sentencias */

sentencia
  : bucle /* esto es para los bucles */
  | comparar /* esto es para los condicionales, if */
  | asignar /* esto es para las asignaciones y operaciones */
  | io /* esto es para entrada y salida, leer y mostrar */

bucle
  : MIENTRAS condicion HACER sentencias FINMIENTRAS '.' /* estructura básica de bucle */
  

comparar
  : SI condicion ENTONCES sentencias FINSI '.' /* estructura básica de condicional */
    | LEE ID '.' /* lectura de variable */
  

asignar
  : ID '=' expresion '.' /* asignación simple */
  

io
  : LEE ID '.' /* lectura de variable */
  | MOSTRAR expresion '.' /* mostrar resultado */
  

expresion
  : ID /* variable */
  | NUM /* número */
  | expresion '+' expresion /* suma */
  | expresion '-' expresion /* resta */
  

condicion
  : expresion '<' expresion /* menor que */
  | expresion '>' expresion /* mayor que */
  | expresion '=' expresion /* igual */
  
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
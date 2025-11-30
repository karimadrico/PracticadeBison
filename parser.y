/* parser.y */
/* Práctica de Bison */
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
  : PROGRAMA ID '.' INICIO sentencias FIN '.'

sentencias
  : sentencia
  | sentencias sentencia

sentencia
  : bucle '.'
  | comparar '.'
  | asignar '.'
  | io '.'

bucle
  : MIENTRAS condicion HACER sentencias FINMIENTRAS

comparar
  : SI condicion ENTONCES sentencias FINSI

asignar
  : ID '=' expresion

io
  : LEE ID
  | MOSTRAR expresion

expresion
  : ID
  | NUM
  | expresion '+' expresion
  | expresion '-' expresion

condicion
  %union {
    int num;
    char *id;
    char *cad;
  }
  %token <id> ID
  %token <num> NUM
  %token <cad> CAD
  %union {
    int num;
    char *id;
    char *cad;
  }
  %token <id> ID
  %token <num> NUM
  %token <cad> CAD
  : expresion '<' expresion
  | expresion '>' expresion
  | expresion '=' expresion
  
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
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern FILE *yyin;
int yylex(void);
void yyerror(const char *s);
char *getNumLbl(void);
typedef enum {
  OP_SUMA,
  OP_RESTA,
  OP_MULTIPLICA,
  OP_DIVIDE
} TipoOperacion;

static void generarOperacionAritmetica(TipoOperacion tipo, int numOperandos, char *target, char *destinoDando);
%}

%union {
  int num;
  char *id;
  char *cad;
}

%type <num> listaExpresiones listaValores
%type <id> targetOpt target optDando

%token <num> NUM
%token <id> ID
%token <cad> CAD

%token PROGRAMA INICIO FIN
%token LEE MOSTRAR SI ENTONCES SINO
%token MIENTRAS HACER FINMIENTRAS
%token EJECUTA VECES USANDO FIN_EJECUTA
%token FINSI
%token HASTAQUE
%token CALCULA FIN_CALCULA MUEVE A DE COMO POR
%token ES IGUAL MAYOR MENOR QUE
%token SUMA RESTA MULTIPLICA DIVIDE DANDO

%left '+' '-'
%left '*' '/'

%define parse.trace

%start programa

%%

programa
  : PROGRAMA ID '.' INICIO sentencias FIN '.'
  ;

sentencias
  : /* vacío */
  | sentencias sentencia
  ;

sentencia
  : bucle '.'
  | comparar '.'
  | asignar '.'
  | io '.'
  | arit '.'
  ;

bucle
  : MIENTRAS condicion HACER sentencias FINMIENTRAS {
        char* lbl0 = getNumLbl();
        char* lbl1 = getNumLbl();
        printf("%s:\n", lbl0);
        // evalúa la condición (la acción de condicion ya genera el código necesario)
        printf("sifalsovea %s\n", lbl1);
        // cuerpo
        printf("vea %s\n", lbl0);
        printf("%s:\n", lbl1);
    }
  | EJECUTA NUM VECES USANDO ID sentencias FIN_EJECUTA {
        char* lbl0 = getNumLbl();
        char* lbl1 = getNumLbl();
        // Inicializa el contador
        printf("valori %s\n", $5); // variable contador
        printf("mete 1\n");
        printf("asigna\n");
        printf("%s:\n", lbl0);
        // ...cuerpo del bucle...
        // Incrementa el contador
        printf("valori %s\n", $5);
        printf("valord %s\n", $5);
        printf("mete 1\n");
        printf("add\n");
        printf("asigna\n");
        // Condición de salida
        printf("valord %s\n", $5);
        printf("valord %d\n", $2); // número de repeticiones
        printf("sub\n");
        printf("siciertovea %s\n", lbl1);
        printf("vea %s\n", lbl0);
        printf("%s:\n", lbl1);
        free($5);
    }
  /* Bucle que ejecuta el bloque y se termina con HASTA-QUE condicion. */
  | EJECUTA sentencias FIN_EJECUTA HASTAQUE condicion {
        char* lbl0 = getNumLbl();
        char* lbl1 = getNumLbl();
        printf("%s:\n", lbl0);
        /* cuerpo ya generado por sentencias */
        printf("valord %s\n", "__dummy__"); /* placeholder no usado */
        /* Evaluar condicion: la acción de condicion genera el código apropiado */
        printf("sifalsovea %s\n", lbl1);
        printf("vea %s\n", lbl0);
        printf("%s:\n", lbl1);
    }
  ;

comparar
  : SI condicion ENTONCES sentencias SINO sentencias FINSI {
      /* caso SI ... SINO ... FINSI */
    }
  | SI condicion ENTONCES sentencias FINSI {
      /* caso SI ... FINSI */
    }
  ;

asignar
  : ID '=' expresion {
      printf("valori %s\n", $1);
      printf("swap\n");
      printf("asigna\n");
      free($1);
    }
  | CALCULA ID '=' expresion FIN_CALCULA {
      printf("valori %s\n", $2);
      printf("swap\n");
      printf("asigna\n");
      free($2);
    }
  | CALCULA ID COMO expresion {
      printf("valori %s\n", $2);
      printf("swap\n");
      printf("asigna\n");
      free($2);
    }
  | MUEVE NUM A ID {
      printf("mete %d\n", $2);
      printf("valori %s\n", $4);
      printf("swap\n");
      printf("asigna\n");
      free($4);
    }
  ;

arit
  : SUMA listaValores targetOpt optDando {
    if (!$3 && !$4) {
      yyerror("La operación SUMA requiere un destino");
      YYERROR;
    }
    generarOperacionAritmetica(OP_SUMA, $2, $3, $4);
  }
  | RESTA listaValores targetOpt optDando {
    if (!$3 && !$4) {
      yyerror("La operación RESTA requiere un destino");
      YYERROR;
    }
    generarOperacionAritmetica(OP_RESTA, $2, $3, $4);
  }
  | MULTIPLICA listaValores targetOpt optDando {
    if (!$3 && !$4) {
      yyerror("La operación MULTIPLICA requiere un destino");
      YYERROR;
    }
    generarOperacionAritmetica(OP_MULTIPLICA, $2, $3, $4);
  }
  | DIVIDE listaValores targetOpt optDando {
    if (!$3 && !$4) {
      yyerror("La operación DIVIDE requiere un destino");
      YYERROR;
    }
    generarOperacionAritmetica(OP_DIVIDE, $2, $3, $4);
  }
  ;

targetOpt
  : target { $$ = $1; }
  | /* vacío */ { $$ = NULL; }
  ;

target
  : DE ID { $$ = $2; }
  | A ID { $$ = $2; }
  | POR ID { $$ = $2; }
  ;

optDando
  : DANDO ID { $$ = $2; }
  | /* vacío */ { $$ = NULL; }
  ;

listaValores
  : expresion { $$ = 1; }
  | listaValores expresion { $$ = $1 + 1; }
  ;

io
  : LEE ID { printf("lee %s\n", $2); free($2); }
  | MOSTRAR listaExpresiones { printf("print %d\n", $2); }
  ;

/* lista de expresiones para MUESTRA; el nonterminal devuelve en .num el
   número de elementos para saber cuántos imprimir. */
listaExpresiones
  : expresion { $$ = 1; }
  | listaExpresiones ',' expresion { $$ = $1 + 1; }
  ;
  ;

expresion
  : ID { printf("valord %s\n", $1); free($1); }
  | NUM { printf("mete %d\n", $1); }
  | CAD { printf("metecad %s\n", $1); free($1); }
  | expresion '*' expresion { printf("mul\n"); }
  | expresion '/' expresion { printf("div\n"); }
  | expresion '+' expresion { printf("add\n"); }
  | expresion '-' expresion { printf("sub\n"); }
  ;

condicion
  : expresion ES IGUAL A expresion { printf("valord %s\nmete 0\nxor\nnot\n", "__dummy__"); }
  | expresion ES MAYOR QUE expresion { printf("sub\n"); }
  | expresion ES MENOR QUE expresion { printf("sub\n"); }
  | expresion '<' expresion { printf("sub\n"); }
  | expresion '>' expresion { printf("sub\n"); }
  | expresion '=' expresion { printf("xor\nnot\n"); }
  ;

%%

static void generarOperacionAritmetica(const char *operacion, char *operandoDestino, char *destinoDando) {
  char *destinoFinal = destinoDando ? destinoDando : operandoDestino;
  if (operandoDestino) {
    printf("valord %s\n", operandoDestino);
    if (strcmp(operacion, "sub") == 0 || strcmp(operacion, "div") == 0) {
      printf("swap\n");
    }
  }
  printf("%s\n", operacion);
  if (!destinoFinal) {
    return;
  }
  printf("valori %s\n", destinoFinal);
  printf("swap\n");
  printf("asigna\n");
  if (destinoDando) {
    free(destinoDando);
  }
  if (operandoDestino) {
    free(operandoDestino);
  }
}

static void generarOperacionAritmetica(TipoOperacion tipo, int numOperandos, char *target, char *destinoDando) {
  const char *opAcumulacion = (tipo == OP_MULTIPLICA || tipo == OP_DIVIDE) ? "mul" : "add";
  for (int i = 1; i < numOperandos; ++i) {
    printf("%s\n", opAcumulacion);
  }

  if (target) {
    printf("valord %s\n", target);
    if (tipo == OP_RESTA || tipo == OP_DIVIDE) {
      printf("swap\n");
    }
    const char *opFinal = (tipo == OP_SUMA) ? "add" :
                          (tipo == OP_RESTA) ? "sub" :
                          (tipo == OP_MULTIPLICA) ? "mul" : "div";
    printf("%s\n", opFinal);
  }

  char *destinoFinal = destinoDando ? destinoDando : target;
  if (!destinoFinal) {
    yyerror("La operación aritmética requiere un destino");
    if (destinoDando) free(destinoDando);
    if (target) free(target);
    return;
  }
  printf("valori %s\n", destinoFinal);
  printf("swap\n");
  printf("asigna\n");

  if (destinoDando) {
    free(destinoDando);
  }
  if (target) {
    free(target);
  }
}

void yyerror(const char *s) {
  fprintf(stderr, "Error de sintaxis: %s\n", s);
}

/* Generador simple de etiquetas */
char *getNumLbl(void) {
  static int cnt = 0;
  char *buf = malloc(16);
  if (!buf) return NULL;
  sprintf(buf, "LBL%d", cnt++);
  return buf;
}

/* Exponer el `main` solo cuando no se compile el ejecutable de prueba del lexer.
   Esto permite compilar `lex.yy.c` con `-DTEST_LEXER` y enlazar con
   `parser.tab.c` sin que haya dos funciones vete al sk`main`. */
#ifndef TEST_LEXER
int main(int argc, char *argv[]) {
  if (argc > 1) {
    FILE *f = fopen(argv[1], "r");
    if (!f) {
      perror("No se pudo abrir el archivo");
      return 1;
    }
    yyin = f;
  }
  yydebug = 1;
  yyparse();
  return 0;
}
#endif

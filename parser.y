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

struct LoopVecesInfo {
  char *lblInicio;
  char *lblFin;
  char *contadorId;
  int limiteEsLiteral;
  int limiteLiteral;
  char *limiteId;
};

static void generarOperacionAritmetica(TipoOperacion tipo, int numOperandos, char *target, char *destinoDando);
%}

%code requires {
typedef struct LoopVecesInfo LoopVecesInfo;
}

%union {
  int num;
  char *id;
  char *cad;
  LoopVecesInfo *loop;
}

%type <num> listaExpresiones listaValores
%type <id> targetOpt target optDando
%type <loop> bucleVecesCabecera

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
  : PROGRAMA ID '.' INICIO sentenciasOpt FIN '.'
  ;

sentencias
  : sentencia
  | sentencias sentencia
  ;

sentenciasOpt
  : /* vacío */
  | sentencias
  ;

sentencia
  : bucle '.'
  | comparar '.'
  | asignar '.'
  | io '.'
  | arit '.'
  ;

bucle
  : MIENTRAS condicion HACER sentenciasOpt FINMIENTRAS {
        char* lbl0 = getNumLbl();
        char* lbl1 = getNumLbl();
        printf("%s:\n", lbl0);
        // evalúa la condición (la acción de condicion ya genera el código necesario)
        printf("sifalsovea %s\n", lbl1);
        // cuerpo
        printf("vea %s\n", lbl0);
        printf("%s:\n", lbl1);
    }
  | EJECUTA bucleVecesCabecera sentenciasOpt FIN_EJECUTA {
        LoopVecesInfo *info = $2;
        printf("valori %s\n", info->contadorId);
        printf("valord %s\n", info->contadorId);
        printf("mete 1\n");
        printf("add\n");
        printf("asigna\n");
        printf("valord %s\n", info->contadorId);
        if (info->limiteEsLiteral) {
          printf("mete %d\n", info->limiteLiteral);
        } else {
          printf("valord %s\n", info->limiteId);
        }
        printf("sub\n");
        printf("siciertovea %s\n", info->lblFin);
        printf("vea %s\n", info->lblInicio);
        printf("%s:\n", info->lblFin);
        free(info->contadorId);
        if (!info->limiteEsLiteral && info->limiteId) {
          free(info->limiteId);
        }
        free(info->lblInicio);
        free(info->lblFin);
        free(info);
    }
  /* Bucle que ejecuta el bloque y se termina con HASTA-QUE condicion. */
  | EJECUTA sentenciasOpt FIN_EJECUTA HASTAQUE condicion {
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

bucleVecesCabecera
  : NUM VECES USANDO ID {
        LoopVecesInfo *info = malloc(sizeof(*info));
        if (!info) {
          yyerror("Sin memoria para el bucle EJECUTA VECES");
          free($4);
          YYERROR;
        }
        info->lblInicio = getNumLbl();
        info->lblFin = getNumLbl();
        info->contadorId = $4;
        info->limiteEsLiteral = 1;
        info->limiteLiteral = $1;
        info->limiteId = NULL;
        printf("valori %s\n", info->contadorId);
        printf("mete 1\n");
        printf("asigna\n");
        printf("%s:\n", info->lblInicio);
        $$ = info;
    }
  | ID VECES USANDO ID {
        LoopVecesInfo *info = malloc(sizeof(*info));
        if (!info) {
          yyerror("Sin memoria para el bucle EJECUTA VECES");
          free($1);
          free($4);
          YYERROR;
        }
        info->lblInicio = getNumLbl();
        info->lblFin = getNumLbl();
        info->contadorId = $4;
        info->limiteEsLiteral = 0;
        info->limiteLiteral = 0;
        info->limiteId = $1;
        printf("valori %s\n", info->contadorId);
        printf("mete 1\n");
        printf("asigna\n");
        printf("%s:\n", info->lblInicio);
        $$ = info;
    }
  ;

comparar
  : SI condicion ENTONCES sentenciasOpt SINO sentenciasOpt FINSI {
      /* caso SI ... SINO ... FINSI */
    }
  | SI condicion ENTONCES sentenciasOpt FINSI {
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

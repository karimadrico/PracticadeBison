/* parser.y */
/* Práctica de Bison */
/* Autor: Karima Drafli Rico */
%{
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;
int yylex(void);
void yyerror(const char *s);
int etiqueta = 0;
char lbl_buf[16];
char* getNumLbl() {
    sprintf(lbl_buf, "LBL%d", etiqueta++);
    return lbl_buf;
}
%}
%union {
    int num;
    char *id;
    char *cad;
    char *lbl;
}
%token <id> ID
%token <num> NUM
%token <cad> CAD
%token PROGRAMA INICIO FIN MIENTRAS HACER FINMIENTRAS SI ENTONCES FINSI LEE MOSTRAR DISPLAY SINO MUESTRA '.'
%token SUMA RESTA MULTIPLICA DIVIDE DANDO
%left '+' '-'
%left '<' '>'
%left '='
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
  | arit '.'

bucle
  : MIENTRAS expresion '<' expresion HACER sentencias FINMIENTRAS {
        char* lbl0 = getNumLbl();
        char* lbl1 = getNumLbl();
        printf("%s:\n", lbl0);
        printf("valord %s\n", $2);
        printf("mete %d\n", $4);
        printf("sub\n");
        printf("sifalsovea %s\n", lbl1);
        // cuerpo
        printf("vea %s\n", lbl0);
        printf("%s:\n", lbl1);
        free($2);
    }

comparar
  : SI condicion ENTONCES sentencias FINSI {
        char* lbl0 = getNumLbl();
        printf("sifalsovea %s\n", lbl0);
        // cuerpo
        printf("%s:\n", lbl0);
    }

asignar
  : ID '=' expresion {
        printf("valori %s\n", $1);
        printf("swap\n");
        printf("asigna\n");
        free($1);
    }

arit
  : SUMA listaValores DANDO ID {
        printf("add\n");
        printf("valori %s\n", $4);
        printf("swap\n");
        printf("asigna\n");
        free($4);
    }
  | SUMA listaValores ID {
        printf("add\n");
        printf("valori %s\n", $3);
        printf("swap\n");
        printf("asigna\n");
        free($3);
    }
  | RESTA listaValores DANDO ID {
        printf("sub\n");
        printf("valori %s\n", $4);
        printf("swap\n");
        printf("asigna\n");
        free($4);
    }
  | RESTA listaValores ID {
        printf("sub\n");
        printf("valori %s\n", $3);
        printf("swap\n");
        printf("asigna\n");
        free($3);
    }
  | MULTIPLICA listaValores DANDO ID {
        printf("mul\n");
        printf("valori %s\n", $4);
        printf("swap\n");
        printf("asigna\n");
        free($4);
    }
  | MULTIPLICA listaValores ID {
        printf("mul\n");
        printf("valori %s\n", $3);
        printf("swap\n");
        printf("asigna\n");
        free($3);
    }
  | DIVIDE listaValores DANDO ID {
        printf("div\n");
        printf("valori %s\n", $4);
        printf("swap\n");
        printf("asigna\n");
        free($4);
    }
  | DIVIDE listaValores ID {
        printf("div\n");
        printf("valori %s\n", $3);
        printf("swap\n");
        printf("asigna\n");
        free($3);
    }

listaValores
  : expresion expresion

io
  : LEE ID { printf("lee %s\n", $2); free($2); }
  | MOSTRAR expresion { printf("valord %s\nprint 1\n", $2); free($2); }

expresion
  : ID { printf("valord %s\n", $1); free($1); }
  | NUM { printf("mete %d\n", $1); }
  | expresion '+' expresion { printf("add\n"); }
  | expresion '-' expresion { printf("sub\n"); }

condicion
  : expresion '<' expresion { printf("sub\n"); }
  | expresion '>' expresion { printf("sub\n"); }
  | expresion '=' expresion { printf("sub\n"); }
  
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
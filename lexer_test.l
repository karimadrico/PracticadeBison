%{
#include <stdio.h>
%}
%option noyywrap
%%
[ \t\n]+          ;
"PROGRAMA"        { printf("KW PROGRAMA\n"); }
[A-Z][A-Z0-9-]*    { printf("ID:%s\n", yytext); }
[0-9]+             { printf("NUM:%s\n", yytext); }
\"[^\"\n]*\"   { printf("CAD:%s\n", yytext); }
.                  { printf("CHAR:%c\n", yytext[0]); }
%%
int main(void) { yylex(); return 0; }

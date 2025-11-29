%{
#include <stdio.h>
%}
%option noyywrap
%%
[ \t\r\n]+   { /* Ignorar */ ; }
.             { return yytext[0]; }
%%

%{
#include <stdio.h>
int l_count = 0;
int w_count = 0;
%}

%%
[a-zA-Z0-9]+     { w_count++; }
\n               { l_count++; }
%%

int yywrap() {
    return 1;
}

void main() {
    printf("Enter text:\n");
    yylex();
    printf("Number of words: %d\n", w_count);
    printf("Number of lines: %d\n", l_count);
    return;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int iskeyword(char buffer[]) {
    char keywords[32][10] = {"auto", "break", "char", "const", "continue"};
    int i;
    for(i = 0; i < 32; i++) {
        if(strcmp(keywords[i], buffer) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[15];
    char operators[] = "+-*/%=";
    FILE *fp;
    int i, j = 0;

    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        printf("error opening file\n");
        exit(0);
    }

    printf("Tokens found\n");

    while((ch = fgetc(fp)) != EOF) {
        for(i = 0; i < strlen(operators); ++i) {
            if(ch == operators[i]) {
                printf("Operator: %c\n", ch);
                break;
            }
        }

        if(isdigit(ch)) {
            printf("Number: %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}

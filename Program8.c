#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[100];
int pos = 0;

void E();
void EPrime();
void T();
void TPrime();
void F();
void advance();

void advance() {
    pos++;
}

void E() {
    T();
    EPrime();
}

void EPrime() {
    if (input[pos] == '+') {
        advance();
        T();
        EPrime();
    }
}

void T() {
    F();
    TPrime();
}

void TPrime() {
    if (input[pos] == '*') {
        advance();
        F();
        TPrime();
    }
}

void F() {
    if (input[pos] == '(') {
        advance();
        E();
        if (input[pos] == ')') {
            advance();
        } else {
            error();
        }
    } else if (input[pos] == 'i' && input[pos + 1] == 'd') {
        advance();
        advance();
    } else {
        error();
    }
}

void error() {
    printf("Syntax error at position %d\n", pos);
    exit(0);
}

void main() {
    printf("Enter expression: ");
    scanf("%s", input);

    E();

    if (input[pos] == '\0') {
        printf("Parsing Successful! Expression is valid.\n");
    } else {
        error();
    }
}
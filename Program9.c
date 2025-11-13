#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[100];
int pos = 0;

void S();
void L();
void LPrime();
void error();

void advance() {
    pos++;
}

void S() {
    if (input[pos] == '(') {
        advance();
        L();
        if (input[pos] == ')') {
            advance();
        } else {
            error();
        }
    } else if (input[pos] == 'a') {
        advance();
    } else {
        error();
    }
}

void L() {
    S();
    LPrime();
}

void LPrime() {
    if (input[pos] == ',') {
        advance();
        S();
        LPrime();
    }
}

void error() {
    printf("Syntax error at position %d\n", pos);
    exit(0);
}

int main() {
    printf("Enter expression: ");
    scanf("%s", input);

    S();

    if (input[pos] == '\0') {
        printf("Parsing Successful! Expression is valid.\n");
    } else {
        error();
    }

    return 0;
}

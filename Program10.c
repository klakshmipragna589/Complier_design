#include <stdio.h>
#include <string.h>
#define N 5

char *NT[N] = {"E", "E'", "T", "T'", "F"};
char *G[N][3] = {
    {"TE'", NULL},
    {"+TE'", "e", NULL},
    {"FT'", NULL},
    {"*FT'", "e", NULL},
    {"(E)", "id", NULL}
};

char FIRST[N][10];
int count[N];

int id(char *s) {
    for (int i = 0; i < N; i++)
        if (strcmp(NT[i], s) == 0)
            return i;
    return -1;
}

bool isNT(char *s) {
    return idx(s) != -1;
}

void addFIRST(int i, char c) {
    for (int j = 0; j < count[i]; j++)
        if (FIRST[i][j] == c)
            return;
    FIRST[i][count[i]++] = c;
}

void computeFirst(int i) {
    for (int p = 0; G[i][p] != NULL; p++) {
        char *prod = G[i][p];
        int j = 0;
        bool allEps = true;

        while (prod[j]) {
            char sym[3] = {prod[j], 0, 0};
            if (prod[j++] == '\') {
                sym[1] = '\';
                j++;
            }
            if (strcmp(sym, "e") == 0) {
                addFIRST(i, 'e');
                break;
            }
            if (!isNT(sym)) {
                addFIRST(i, sym[0]);
                allEps = false;
                break;
            }
            int k = idx(sym);
            if (count[k]== 0)
                computeFirst(k);
            bool hasEps = false;
            for (int m = 0; m < count[k]; m++) {
                if (FIRST[k][m] == 'e')
                    hasEps = true;
                else
                    addFIRST(i, FIRST[k][m]);
            }
            if (!hasEps) {
                allEps = false;
                break;
            }
            j++;
        }
        if (allEps)
            addFIRST(i, 'e');
    }
}

int main() {
    for (int i = 0; i < N; i++)
        computeFirst(i);

    for (int i = 0; i < N; i++) {
        printf("FIRST(%s) = { ", NT[i]);
        for (int j = 0; j < count[i]; j++) {
            printf("%c", FIRST[i][j]);
            if (j < count[i] - 1)
                printf(", ");
        }
        printf(" }\n");
    }
    return 0;
}

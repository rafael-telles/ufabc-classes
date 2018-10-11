#include <stdlib.h>

void insere(char* pilha, char* palavra, int* n) {
    int i;
    for (i = 0; i < 4; i++) {
        pilha[(*n) * 4 + i] = palavra[i];
    }
    (*n)++;
    pilha[(*n) * 4] = '\0';
}

void verifica(char* pilha, int* n, int* brindes) {
    if (*n < 2) {
        return;
    }

    int i;
    for (i = 0; i < 4; i++) {
        char c1 = pilha[(*n - 2) * 4 + i];
        char c2 = pilha[(*n - 1) * 4 + (3 - i)];
        if (c1 != c2) {
            return;
        }
    }
    (*n) -= 2;
    pilha[(*n) * 4] = '\0';
    (*brindes)++;
    if (*n == 0) {
        insere(pilha, "FACE", n);
    }
}

void input(char* pilha, int* n, int* brindes) {
    char p[4];
    int i;
    for (i = 0; i < 4; i++) {
        scanf(" %c", p + i);
    }

    insere(pilha, p, n);
    verifica(pilha, n, brindes);
}

int main() {
    int m;
    scanf("%d\n", &m);

    char* pilha = (char*) malloc(sizeof(char) * (4 * m + 1));
    int n = 0;
    int brindes = 0;

    insere(pilha, "FACE", &n);
    while (m > 0) {
        input(pilha, &n, &brindes);
        m--;
    }
    free(pilha);

    printf("%d\n", brindes);

    return 0;
}

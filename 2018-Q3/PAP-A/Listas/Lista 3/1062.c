#include <stdlib.h>

typedef struct pilha_s {
    int n;
    int* vals;
} pilha_t;

pilha_t* criar_pilha(int tamanho) {
    pilha_t* p = malloc(sizeof(pilha_t));
    p->n = 0;
    p->vals = malloc(sizeof(int) * tamanho);

    return p;
}

void free_pilha(pilha_t* p) {
    free(p->vals);
    free(p);
}

int vazia(pilha_t* p) {
    return p->n == 0 ? 1 : 0;
}

void push_pilha(pilha_t* p, int a) {
    p->vals[(p->n)++] = a;
}

int pop_pilha(pilha_t* p) {
    return p->vals[--(p->n)];
}

int peek_pilha(pilha_t* p) {
    return p->vals[p->n - 1];
}

void print_pilha(pilha_t* p) {
    printf("P[");

    int i;
    for (i = 0; i < p->n; i++) {
        printf("%d,", p->vals[i]);
    }
    printf("]\n");
}

int main() {
    while(1) {
        int nv;
        scanf("%d", &nv);
        if (nv == 0) {
            return 0;
        }

        int i, j;
        while(1) {
            int exit = 0;
            int exit1 = 0;

            pilha_t* a = criar_pilha(nv);
            pilha_t* est = criar_pilha(nv);
            
            int v[nv];
            for (i = 0; i < nv; i++) {
                scanf("%d", v+i);
                if (v[i] == 0) {
                    exit = 1;
                    break;
                }
            }
            if (exit) {
                nv = 0;
                break;
            }
            
            for (i = nv; i > 0; i--) {
                push_pilha(a, i);
            }

            int valido = 0;
            i = 0;
            while(1) {
                if (vazia(a) && vazia(est)) {
                    valido = 1;
                    break;
                }

                if (!vazia(est)) {
                    j = peek_pilha(est);
                    if (j == v[i]) {
                        i++;
                        pop_pilha(est);
                        continue;
                    }
                }

                if (!vazia(a)) {
                    j = pop_pilha(a);
                    if (j == v[i]) {
                        i++;
                        continue;
                    } else {
                        push_pilha(est, j);
                        continue;
                    }
                }

                break;
            }

            if (valido) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            free_pilha(a);
            free_pilha(est);
        }
        printf("\n");
    }

    return 0;
}
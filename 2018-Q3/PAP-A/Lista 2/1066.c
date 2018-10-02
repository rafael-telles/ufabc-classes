#include <stdlib.h>

int main() {
    int i, a, pares = 0, positivos = 0, zeros = 0;
    for (i = 0; i < 5; i++) {
        scanf("%d", &a);
        if (a % 2 == 0) {
            pares++;
        }
        if (a > 0) {
        	positivos++;
        }
        if (a == 0) {
        	zeros++;
        }
    }

    printf("%d valor(es) par(es)\n", pares);
    printf("%d valor(es) impar(es)\n", 5-pares);
    printf("%d valor(es) positivo(s)\n", positivos);
    printf("%d valor(es) negativo(s)\n", 5-positivos-zeros);

    return 0;
}
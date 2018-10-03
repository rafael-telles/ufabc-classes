#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, a, n;
    double preco;
    double total = 0;
    for (i = 0; i < 2; i++) {
        scanf("%d %d %lf", &a, &n, &preco);
        total += n * preco;
    }

    printf("VALOR A PAGAR: R$ %.2f\n", total);
    return 0;
}

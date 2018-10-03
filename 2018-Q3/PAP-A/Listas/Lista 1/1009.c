#include <stdio.h>
#include <stdlib.h>

int main() {
        char *nome = malloc(128);
        fgets(nome, 128, stdin);

        double a, b;

        scanf("%lf", &a);
        scanf("%lf", &b);

        printf("TOTAL = R$ %.2f\n", a + 0.15 * b);
        return 0;
}

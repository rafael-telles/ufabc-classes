#include <stdio.h>

int main() {
    double b;
    scanf("%lf", &b);

    int a = b * 100;

    int i;

    int notas[] = {10000, 5000, 2000, 1000, 500, 200};
    printf("NOTAS:\n");
    for (i = 0; i < 6; i++) {
        printf("%d nota(s) de R$ %.2f\n", a / notas[i], notas[i] / 100.0);
        a %= notas[i];
    }

    int moedas[] = {100, 50, 25, 10, 5, 1};
    printf("MOEDAS:\n");
    for (i = 0; i < 6; i++) {
        printf("%d moeda(s) de R$ %.2f\n", a / moedas[i], moedas[i] / 100.0);
        a %= moedas[i];
    }


    return 0;
}

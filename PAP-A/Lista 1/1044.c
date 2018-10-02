#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    if (b < a) {
        int aux = a;
        a = b;
        b = aux;
    }

    if (b % a == 0 || abs(b) == 1) {
        printf("Sao Multiplos\n");
    } else {
        printf("Nao sao Multiplos\n");
    }

    return 0;
}

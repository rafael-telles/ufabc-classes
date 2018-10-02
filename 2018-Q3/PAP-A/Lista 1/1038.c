#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    double precos[] = {4, 4.5, 5, 2, 1.5};

    double total = precos[a-1] * b;

    printf("Total: R$ %.2f\n", total);

    return 0;
}

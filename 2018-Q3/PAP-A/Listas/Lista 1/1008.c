#include <stdio.h>
int main() {
        int n, horas;
        double preco;

        scanf("%d", &n);
        scanf("%d", &horas);
        scanf("%lf", &preco);

        printf("NUMBER = %d\n", n);
        printf("SALARY = U$ %.2f\n", horas * preco);
        return 0;
}

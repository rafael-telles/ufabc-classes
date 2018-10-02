#include <stdlib.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y)) 

int main() {
    double renda;
    scanf("%lf", &renda);

    if (renda <= 2000.00) {
        printf("Isento\n");
        return 0;
    } 

    double imposto = 0;

    renda -= 2000.00;
    imposto += MIN(renda, 1000.00) * 0.08;

    renda -= MIN(renda, 1000.00);
    imposto += MIN(renda, 1500.00) * 0.18;

    renda -= MIN(renda, 1500.00);
    imposto += renda * 0.28;

    printf("R$ %.2f\n", imposto);

	return 0;
}
#include <stdlib.h>

int main() {
    double salario;
    scanf("%lf", &salario);

    double reajuste;
    if (salario <= 400.0) {
    	reajuste = 0.15;
    } else if (400.0 < salario && salario <= 800.0) {
    	reajuste = 0.12;
    } else if (800.0 < salario && salario <= 1200.0) {
    	reajuste = 0.10;
    } else if (1200.0 < salario && salario <= 2000.0) {
    	reajuste = 0.07;
    } else {
    	reajuste = 0.04;
    }

	printf("Novo salario: %.2f\n", salario * (1 + reajuste));
	printf("Reajuste ganho: %.2f\n", salario * reajuste);
	printf("Em percentual: %.0f %%\n", reajuste * 100.0);

	return 0;
}
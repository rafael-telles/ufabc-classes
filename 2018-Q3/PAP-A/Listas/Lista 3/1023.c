#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX 200

int main() {
	int cidade = 0;
	while(++cidade) {
		int v[1000];
		int n, i, moradores, consumo;
		double media = 0;
		int contagem = 0;

		for (i = 0; i < 1000; i++) {
			v[i] = 0;
		}
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		for (i = 0; i < n; i++) {
			scanf("%d %d", &moradores, &consumo);
			media += consumo;
			contagem += moradores;
			consumo /= moradores;
			v[consumo] += moradores;
		}
		media /= contagem;

		if (cidade > 1) {
			printf("\n");
		}
		printf("Cidade# %d:\n", cidade);
		int first = 1;
		for (i = 0; i < 1000; i++) {
			if (v[i]) {
				if (!first) {
					printf(" ");
				}
				printf("%d-%d", v[i], i);
				first = 0;
			}
		}
		printf("\nConsumo medio: %0.2lf m3.\n", trunc(media*100)/100.0);
	}
}
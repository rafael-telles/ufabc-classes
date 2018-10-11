#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE_MAX 50

typedef struct state_s {
	int brinquedos;
	int peso;
	int sobra;
} state_t;

inline int max(int a, int b) {
	return a > b ? a : b;
}

dp(int N, int* quantidades, int* pesos, int* rb, int* rp, int* rs) {
	int rbrinquedos[N][CAPACIDADE_MAX + 1];
	int rpesos[N][CAPACIDADE_MAX + 1];
	int rsobra[N][CAPACIDADE_MAX + 1];
	memset(rbrinquedos, 0, sizeof(int)*N*(CAPACIDADE_MAX+1));
	memset(rpesos, 0, sizeof(int)*N*(CAPACIDADE_MAX+1));
	memset(rsobra, 0, sizeof(int)*N*(CAPACIDADE_MAX+1));

	int i, c;
	i = N - 1;
	int peso = pesos[i];
	int quantidade = quantidades[i];
	for (c = 0; c < peso; c++) {
		rsobra[i][c] = N;
	}
	for (c = peso; c <= CAPACIDADE_MAX; c++) {
		rbrinquedos[i][c] = quantidade;
		rpesos[i][c] = peso;
		rsobra[i][c] = N - 1;
	}
	i--;
	for (; i >= 0; i--) {
		peso = pesos[i];
		quantidade = quantidades[i];
		for (c = 0; c < peso; c++) {
			rbrinquedos[i][c] = rbrinquedos[i + 1][c];
			rpesos[i][c] = rpesos[i + 1][c];
			rsobra[i][c] = rsobra[i + 1][c];
		}
		for (c = peso; c <= CAPACIDADE_MAX; c++) {
			int brinquedos_conta = quantidade + rbrinquedos[i + 1][c - peso];
			int brinquedos_pula = rbrinquedos[i + 1][c];
			if (brinquedos_conta > brinquedos_pula) {
				rbrinquedos[i][c] = brinquedos_conta;
				rpesos[i][c] = peso + rpesos[i + 1][c - peso];
				rsobra[i][c] = rsobra[i + 1][c - peso] - 1;
			} else {
				rbrinquedos[i][c] = brinquedos_pula;
				rpesos[i][c] = rpesos[i + 1][c];
				rsobra[i][c] = rsobra[i + 1][c];
			}
		}
	}

	*rb = rbrinquedos[0][CAPACIDADE_MAX];
	*rp = rpesos[0][CAPACIDADE_MAX];
	*rs = rsobra[0][CAPACIDADE_MAX];
}

int main3(int N, int quantidades[N], int pesos[N]) {
	int visited[N];
	int i;
	for (i = 0; i < N; i++) {
		visited[i] = 0;
	}

	int brinquedos, peso, sobra;
	dp(N, quantidades, pesos, &brinquedos, &peso, &sobra);

	printf("%d brinquedos\n", brinquedos);
	printf("Peso: %d kg\n", peso);
	printf("sobra(m) %d pacote(s)\n\n", sobra);
}

int main2() {
	int N;
	scanf("%d", &N);

	int quantidades[N];
	int pesos[N];
	int i;
	for (i = 0; i < N; i++) {
		scanf("%d %d", quantidades + i, pesos + i);
	}

	main3(N, quantidades, pesos);

	return 0;
}

int main() {
	int N;
	scanf("%d", &N);

	while(N-- > 0) {
		main2();
	}

	return 0;
}
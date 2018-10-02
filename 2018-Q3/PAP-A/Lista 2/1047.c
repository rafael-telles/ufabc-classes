#include <stdlib.h>

int main() {
    int h0, m0, hf, mf;
    scanf("%d %d %d %d", &h0, &m0, &hf, &mf);

    int duracao = (hf * 60 + mf) - (h0 * 60 + m0);
    if (duracao <= 0) {
    	duracao += 24 * 60;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao / 60, duracao % 60);

	return 0;
}
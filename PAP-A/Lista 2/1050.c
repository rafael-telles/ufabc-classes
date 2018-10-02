#include <stdlib.h>

int main() {
    int ddd;
    scanf("%d", &ddd);

    switch(ddd) {
        case 61: printf("Brasilia\n"); return 0;
        case 71: printf("Salvador\n"); return 0;
        case 11: printf("Sao Paulo\n"); return 0;
        case 21: printf("Rio de Janeiro\n"); return 0;
        case 32: printf("Juiz de Fora\n"); return 0;
        case 19: printf("Campinas\n"); return 0;
        case 27: printf("Vitoria\n"); return 0;
        case 31: printf("Belo Horizonte\n"); return 0;
        default: printf("DDD nao cadastrado\n"); return 0;
    }

	return 0;
}
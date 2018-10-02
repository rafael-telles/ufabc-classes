#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    int notas[] = {100, 50, 20, 10, 5, 2, 1};
    int i;
    printf("%d\n", a);
    for (i = 0; i < 7; i++) {
    	printf("%d nota(s) de R$ %d,00\n", a / notas[i], notas[i]);
    	a %= notas[i];
    }

    return 0;
}

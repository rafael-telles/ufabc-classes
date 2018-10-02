#include <stdlib.h>

int main() {
    int i, n, x, r = 0, s = 0, c = 0;
    char tipo;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
    	scanf("%d %c", &x, &tipo);
        switch (tipo) {
            case 'R': r += x; break;
            case 'S': s += x; break;
            case 'C': c += x; break;
        }
    }

    printf("Total: %d cobaias\n", r+s+c);
    printf("Total de coelhos: %d\n", c);
    printf("Total de ratos: %d\n", r);
    printf("Total de sapos: %d\n", s);
    printf("Percentual de coelhos: %.2f %%\n", 100.0*c/(r+s+c));
    printf("Percentual de ratos: %.2f %%\n", 100.0*r/(r+s+c));
    printf("Percentual de sapos: %.2f %%\n", 100.0*s/(r+s+c));

    return 0;
}
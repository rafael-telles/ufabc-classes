#include <stdlib.h>

int main() {
    double a, mean;
    int i, c = 0;
    for (i = 0; i < 6; i++) {
        scanf("%lf", &a);
        if (a > 0) {
            c++;
            mean += a;
        }
    }
    mean /= c;

    printf("%d valores positivos\n", c);
    printf("%.1lf\n", mean);

    return 0;
}
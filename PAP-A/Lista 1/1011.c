#include <stdio.h>
#include <stdlib.h>

int main() {
    double r;
    scanf("%lf", &r);

    printf("VOLUME = %.3lf\n", (4.0/3) * 3.14159 * r * r * r);
    return 0;
}

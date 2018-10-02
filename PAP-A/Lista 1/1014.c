#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, b;
    scanf("%lf", &a);
    scanf("%lf", &b);

	printf("%.3f km/l\n", a / b);
    return 0;
}

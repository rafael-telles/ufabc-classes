#include <stdio.h>
#include <math.h>

int swap(double* a, double* b) {
    double aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    double n[3], a, b, c;
    scanf("%lf %lf %lf", n+0, n+1, n+2);

    a = n[0];
    b = n[1];
    c = n[2];

    if (n[2] < n[0]) swap(n+0, n+2);
    if (n[2] < n[1]) swap(n+1, n+2);
    if (n[1] < n[0]) swap(n+0, n+1);

    double p = n[0] + n[1] + n[2];

    if (n[2] < n[0] + n[1]) {
        printf("Perimetro = %.1f\n", p);
    } else {
        double area = (a+b)*c/2.0;
        printf("Area = %.1f\n", area);
    }

    return 0;
}

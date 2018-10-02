#include <stdio.h>
#include <math.h>

int swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int n[3];
    scanf("%d %d %d", n+0, n+1, n+2);

    int m[3];
    int i;
    for (i = 0; i < 3; i++) {
        m[i] = n[i];
    }

    if (n[2] < n[0]) swap(n+0, n+2);
    if (n[2] < n[1]) swap(n+1, n+2);
    if (n[1] < n[0]) swap(n+0, n+1);

    for (i = 0; i < 3; i++) {
        printf("%d\n", n[i]);
    }
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf("%d\n", m[i]);
    }

    return 0;
}

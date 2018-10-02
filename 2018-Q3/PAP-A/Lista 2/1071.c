#include <stdlib.h>

int swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    if (b < a) swap(&a, &b);
    
    a++;
    
    int sum = 0;
    while (a < b) {
        if (a % 2 != 0) {
            sum += a;
        }
        a++;
    }

    printf("%d\n", sum);

    return 0;
}
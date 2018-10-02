#include <stdlib.h>

int main() {
    int i, n, x, c = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x >= 10 && x <= 20) {
            c++;
        }
    }

    printf("%d in\n", c);
    printf("%d out\n", n-c);

    return 0;
}
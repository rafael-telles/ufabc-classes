#include <stdlib.h>

int main() {
    int i, a;
    scanf("%d", &a);

    for (i = 1; i <= a; i += 2) {
        printf("%d\n", i);
    }

    return 0;
}
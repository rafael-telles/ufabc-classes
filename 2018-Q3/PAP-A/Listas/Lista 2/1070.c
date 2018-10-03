#include <stdlib.h>

int main() {
    int i, a;
    scanf("%d", &a);
    if (a % 2 == 0) a++;

    for (i = 0; i < 6; i++) {
        printf("%d\n", a + i * 2);
    }

    return 0;
}
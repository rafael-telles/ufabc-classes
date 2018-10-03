#include <stdlib.h>

int main() {
    float i, a, j;
    for (i = 0; i <= 2.1; i += 0.2) {
        for (a = 1; a <= 3; a++) {
            j = a + i;
            if (i == 0 || i == 1 || i > 1.9) {
                printf("I=%.0f J=%.0f\n", i, j);
            } else {
                printf("I=%.1f J=%.1f\n", i, j);
            }
        }
    }

    return 0;
}

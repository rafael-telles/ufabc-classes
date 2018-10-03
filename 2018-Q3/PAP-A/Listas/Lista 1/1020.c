#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    int y = a / 365;
    a %= 365;
    int m = a / 30;
    a %= 30;
    int d = a;

    printf("%d ano(s)\n", y);
    printf("%d mes(es)\n", m);
    printf("%d dia(s)\n", d);
    return 0;
}

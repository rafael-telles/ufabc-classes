#include <stdlib.h>

int input() {
    int d, h, m, s;
    scanf("Dia %d\n", &d);
    scanf("%d : %d : %d\n", &h, &m, &s);

    return (((24 * d) + h) * 60 + m) * 60 + s;
}

int main() {
    int inicio, fim;
    inicio = input();
    fim = input();

    int dur = fim - inicio;

    int d, h, m, s;
    d = dur / (60 * 60 * 24);
    dur = dur % (60 * 60 * 24);
    h = dur / (60 * 60);
    dur = dur % (60 * 60);
    m = dur / 60;
    dur = dur % 60;
    s = dur;

    printf("%d dia(s)\n", d);
    printf("%d hora(s)\n", h);
    printf("%d minuto(s)\n", m);
    printf("%d segundo(s)\n", s);

    return 0;
}
#include <stdio.h>

int maior(int n, int v[]) {
    if (n == 1) {
        return v[0];
    }
    int x = maior(n - 1, v);
    if (x > v[n - 1]) {
        return x;
    } else {
        return v[n - 1];
    }
}

int main() {
    int v[3];
    int res;
    
    scanf("%d %d %d", &v[0], &v[1], &v[2]);
    
    res = maior(3, v);
    
    printf("%d eh o maior\n", res);
    
    return 0;
}

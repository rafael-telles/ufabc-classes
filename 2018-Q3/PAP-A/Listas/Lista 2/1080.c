#include <stdlib.h>
#include <limits.h>

int main() {
    int max, maxi, i, n;
    max = INT_MIN;
    for (i = 0; i < 100; i++) {
    	scanf("%d", &n);
    	if (n > max) {
    		maxi = i;
    		max = n;
    	}
    }

    printf("%d\n", max);
    printf("%d\n", maxi+1);

    return 0;
}
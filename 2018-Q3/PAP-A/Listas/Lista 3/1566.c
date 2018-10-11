#include <stdlib.h>

#define MAX 230

int main() {
	int n;
	scanf("%d", &n);

	while (n-- > 0) {
		int m;
		scanf("%d", &m);

		int A[m], B[m];
		int i;
		for (i = 0; i < m; i++) {
			scanf(" %d", A+i);
		}

		int C[MAX + 1];
		for (i = 0; i <= MAX; i++) {
			C[i] = 0;
		}
		for (i = 0; i < m; i++) {
			C[A[i]]++;
		}
		for (i = 1; i <= MAX; i++) {
			C[i] += C[i - 1];
		}
		for (i = 0; i < m; i++) {
			B[C[A[i]] - 1] = A[i];
			C[A[i]]--;
		}

		for (i = 0; i < m; i++) {
			printf("%d", B[i]);
			if (i < m - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
}
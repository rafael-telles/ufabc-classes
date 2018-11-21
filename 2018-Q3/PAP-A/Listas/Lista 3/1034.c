#include <stdio.h>

int swap(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

int sort(int* v, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (v[i] > v[j]) {
				swap(v+i, v+j);
			}
		}
	}
}

int main2() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);

	int b[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &(b[i]));
	}
	sort(b, n);

	int r[m+1];
	memset(r, 0, m+1);
	
	for (i = 0; i < m+1; i++) {
		r[i] = 1000001;
		for (j = 0; j < n; ++j) {
			int bj = b[j];
			if (bj == i) {
				r[i] = 1;
			} else if (bj < i) {
				if (r[i - bj] + 1 < r[i]) {
					r[i] = r[i - bj] + 1;
				}
			} else {
				break;
			}

		}	
	}

	printf("%d\n", r[m]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		main2();
	}

	return 0;
}
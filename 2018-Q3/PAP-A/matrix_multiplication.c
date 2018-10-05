#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
	int n = 2000;
	double *A = (double*) malloc(n*n * sizeof(double));
	double *B = (double*) malloc(n*n * sizeof(double));
	double *C = (double*) malloc(n*n * sizeof(double));

	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i * n + j] = 1 + (rand() % 10)/100.0;
			B[i * n + j] = 1 + (rand() % 10)/100.0;
			C[i * n + j] = 0;
		}
	}
	
	#pragma omp parallel for private(i, j, k)
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				C[i * n + j] += A[i * n + k] + B[k * n + j];
			}
		}
	}

	printf("%lf\n", C[0]);
}

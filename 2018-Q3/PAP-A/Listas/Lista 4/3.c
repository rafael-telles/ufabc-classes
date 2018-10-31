#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main() {
    FILE *in = fopen("3_in.txt", "r");
    FILE *out = fopen("3_out.txt", "w");

    int n, p, q;
    fscanf(in, "%d %d", &n, &p);
    
    double *A, *U, *L;
    A = (double*) calloc(n * n, sizeof(double));
    U = (double*) calloc(n * n, sizeof(double));
    L = (double*) calloc(n * n, sizeof(double));

    for(int x=0; x<p; x++){
        int i, j;
        double v;
        fscanf(in, "%d %d %lf", &i, &j, &v);
        i--;
        j--;

        A[i * n + j] = v;
    }

    int i, j, k;

    p = 0;
    q = 0;
    for (i = 0; i < n; i++) {
        #pragma omp parallel for private(k, j) reduction(+:q)
        for (j = i; j < n; j++) {
            double s = 0;
            for (k = 0; k < i; k++) {
                s += L[i * n + k] * U[k * n + j];
            }
            U[i * n + j] = A[i * n + j] - s;
            if (U[i * n + j] != 0) {
                q++;
            }
        }

        #pragma omp parallel for private(k, j) reduction(+:p)
        for (j = i; j < n; j++) {
            if (i == j) {
                L[j * n + i] = 1;
            } else {
                double s = 0;
                for (k = 0; k < i; k++) {
                    s += L[j * n + k] * U[k * n + i];
                }
                L[j * n + i] = (A[j * n + i] - s) / U[i * n + i];
            }
            if (L[j * n + i] != 0) {
                p++;
            }
        }
    }

    fprintf(out, "%d %d %d\n", n, p, q);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (L[i * n + j] != 0) {
                fprintf(out, "%d %d %.4lf\n", i+1, j+1, L[i * n + j]);
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (U[i * n + j] != 0) {
                fprintf(out, "%d %d %.4lf\n", i+1, j+1, U[i * n + j]);
            }
        }
    }

    free(A);
    free(L);
    free(U);
    fclose(in);
    fclose(out);
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main() {
    FILE *in = fopen("1_in.txt", "r");
    FILE *out = fopen("1_out.txt", "w");

    int n, p, q;
    fscanf(in, "%d %d %d", &n, &p, &q);
    
    double *A, *B, *C;
    A = (double*) calloc(n * n, sizeof(double));
    B = (double*) calloc(n * n, sizeof(double));
    C = (double*) calloc(n * n, sizeof(double));

    for(int x=0; x<p; x++){
        int i, j;
        double v;
        fscanf(in, "%d %d %lf", &i, &j, &v);
        i--;
        j--;

        A[i * n + j] = v;
    }
    for(int x=0; x<q; x++){
        int i, j;
        double v;
        fscanf(in, "%d %d %lf", &i, &j, &v);
        i--;
        j--;

        B[i * n + j] = v;
    }
    int i, j, k;
    int c = 0;
    for (i = 0; i < n; i++) {
        #pragma omp parallel for private(j, k) reduction(+:c)
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
            if (C[i * n + j] != 0) {
                c++;
            }
        }
    }
    fprintf(out, "%d %d\n", n, c);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (C[i * n + j] != 0) {
                fprintf(out, "%d %d %.4lf\n", i+1, j+1, C[i * n + j]);
            }
        }
    }

    free(A);
    free(B);
    free(C);
    fclose(in);
    fclose(out);
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>

int main() {
    FILE *in = fopen("4_in.txt", "r");
    FILE *out = fopen("4_out.txt", "w");

    int n;
    fscanf(in, "%d", &n);
    
    double *v, *v2;
    v = (double*) calloc(n, sizeof(double));
    v2 = (double*) calloc(n, sizeof(double));

    int i, j, k;
    for(i = 0; i < n; i++){
        fscanf(in, "%lf", &(v[i]));
        v2[i] = v[i];
    }

    int ln = ceil(log2(n));
    for (i = 0; i < ln; i++) {
        int is = pow(2, i);

        #pragma omp parallel for private(j) shared(v2, v)
        for (j = 0; j < n; j++) {
            v2[j] = v[j];
            if (j >= is) {
                v2[j] += v[j - is];
            }
        }
        memcpy(v, v2, n * sizeof(double));
    }

    fprintf(out, "%d\n", n);
    for (i = 0; i < n; i++) {
        fprintf(out, "%.4lf\n", v2[i]);
    }

    free(v);
    free(v2);
    fclose(in);
    fclose(out);
    return 0;
}
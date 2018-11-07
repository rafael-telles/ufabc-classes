#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>

int main() {
    FILE *in = fopen("5_in.txt", "r");
    FILE *out = fopen("5_out.txt", "w");

    int n, m;
    fscanf(in, "%d %d", &n, &m);
    
    double *A, *Am, *Amn;
    A = (double*) calloc(n * m, sizeof(double));
    Am = (double*) calloc(m, sizeof(double));
    Amn = (double*) calloc(m * m, sizeof(double));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fscanf(in, "%lf", &(A[i*m+j]));
        }
    }

    #pragma omp parallel for
    for(int k = 0; k < m; k++){
        double am = 0;
        for(int i = 0; i < n; i++){
            am += A[i*m+k];
        }
        Am[k] = am / n;

        #pragma omp parallel for
        for(int l = 0; l < m; l++){
            double amn = 0;
            for(int i = 0; i < n; i++){
                amn += A[i*m+k] * A[i*m+l];
            }
            Amn[k*m+l] = amn / n;
        }
    }

    fprintf(out, "%d\n", m);
    for(int k = 0; k < m; k++){
        for(int l = 0; l < m; l++){
            double Mkl = Amn[k*m+l] - Am[k] * Am[l];
            fprintf(out, "%.2lf\t", Mkl);
        }
        fprintf(out, "\n");
    }

    free(A);
    free(Am);
    free(Amn);
    fclose(in);
    fclose(out);
    return 0;
}
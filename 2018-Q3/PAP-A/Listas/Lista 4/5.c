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

    int i, j, k, l;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            fscanf(in, "%lf", &(A[i*m+j]));
        }
    }

    for(k = 0; k < m; k++){
        double am = 0;
        for(i = 0; i < n; i++){
            am += A[i*m+k];
        }
        Am[k] = am / n;

        for(l = 0; l < m; l++){
            double amn = 0;
            for(i = 0; i < n; i++){
                amn += A[i*m+k] * A[i*m+l];
            }
            Amn[k*m+l] = amn / n;
        }
    }

    fprintf(out, "%d\n", m);
    for(k = 0; k < m; k++){
        for(l = 0; l < m; l++){

            // 1/n * (sum (aik*ail) - sum(aik*al) - sum(ak*ail) + sum(ak*al))
            // 1/n * (sum (aik*ail) - sum(aik*al) - sum(ak*ail) + n*ak*al)
            // 1/n * (sum (aik*ail) - sum(ail)/n*sum(aik))

            double Mkl = 0;
            for(i = 0; i < n; i++){
                Mkl += (Amn[i*m+k] - Am[k]) * (A[i*m+l] - Am[l]);
            }
            Mkl /= n;
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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
	int n = 1000;
	int *a = NULL;
	a = (int*) malloc(n * sizeof(int));

	int i;
	for (i=n; i--;) {
		a[i] = i;
	}


	long long sum = 0;
	long long sum2 = 0;

	#pragma omp parallel
	{

		#pragma omp for reduction(+:sum) reduction(+:sum2)
		for (i = 0; i < n; i++) {
			sum += a[i];
			sum2 += a[i] * a[i];
		}
	}

	double mean = sum / (double) n;
	double var = (sum2 - 2 * mean * sum + n * (mean*mean)) / n;
	double stdev = sqrt(var);

	printf("sum: %.2lld\n", sum);
	printf("sum2: %.2lld\n", sum2);
	printf("mean: %.2lf\n", mean);
	printf("var: %.2lf\n", var);
	printf("stdev: %.2lf\n", stdev);
	return 0;
}

#include <stdio.h>
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

	omp_set_num_threads(4);
	// omp_set_dynamic(1);
	#pragma omp parallel default(none) shared(n, a) private(i)
	{
		int id = omp_get_thread_num();

		int count = 0;
		#pragma omp for
		for(i=0; i<n; i++) {
			printf("[%d] - %2d\n", id, i[a]);
			count++;
		}
		printf("Fim [%d] - count: %d\n", id, count);
	}

	return 0;
}

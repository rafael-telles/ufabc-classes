#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{

	int val = 10;
	#pragma omp parallel
	{
		printf("Starting Thread %d --- %d\n", omp_get_thread_num(), val);
		printf("Finishing Thread %d --- %d\n", omp_get_thread_num(), val);
	}

	return 0;
}

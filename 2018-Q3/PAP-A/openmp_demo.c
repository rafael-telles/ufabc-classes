#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
	#pragma omp parallel
	{
		printf("Starting Thread %d\n", omp_get_thread_num());
		printf("Finishing Thread %d\n", omp_get_thread_num());
	}
	return 0;
}

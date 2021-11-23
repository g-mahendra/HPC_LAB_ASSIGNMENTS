#include <omp.h>
#include <stdio.h>

int main() 
{
	// omp_set_num_threads(8);
	#pragma omp parallel 
	{
		printf("Hello! From 2018BTECS00033 with thread number = %d\n", omp_get_thread_num());
	}
	return 0;
}

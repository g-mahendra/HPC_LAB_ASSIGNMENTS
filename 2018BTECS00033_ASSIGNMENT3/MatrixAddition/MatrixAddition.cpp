#include <omp.h>
#include <stdio.h>
#define CHUNK 500

using namespace std;

int main()
{
	int size = 1000;
	
	int** matrix1 = new int*[size];
	int** matrix2 = new int*[size];
	int** res = new int*[size];
		
	for (int i = 0; i < size; i++) {
        matrix1[i] = new int[size];
    	matrix2[i] = new int[size];
    	res[i] = new int[size];
	}
	
	omp_set_num_threads(4);
	double time = omp_get_wtime();
	#pragma omp parallel
	{
		#pragma omp for schedule(static, CHUNK) 
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
			{
				matrix1[i][j] = 2;
				matrix2[i][j] = 3;
			}
		}	
		
		// using static and dynamic schedule for computations
		#pragma omp for schedule(static, CHUNK)
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
			{
				res[i][j] = matrix1[i][j]+matrix2[i][j];
			}
		}
	}
		
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
			printf(" %d ", res[i][j]);
	
	printf("Calculated in %f time\n", omp_get_wtime()-time);

	delete[] matrix1;
	delete[] matrix2;
	delete[] res;
		
	return 0;
}

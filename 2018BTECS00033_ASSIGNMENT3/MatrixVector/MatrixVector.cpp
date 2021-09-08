#include<iostream>
#include<stdio.h>
#include<omp.h>
#define NUM 4

using namespace std;

int main()
{
	int size=0;
	printf("Enter size of matrix\n");
	scanf("%d", &size);
	omp_set_num_threads(NUM);
	int* matrix = new int[size*size];
	int* vector = new int[size];
	int* resVector = new int[size];
	double time = omp_get_wtime();
	#pragma omp parallel
	{
		#pragma omp for
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
				*(matrix+i*size+j) = 2;
		}
		#pragma omp for
		for(int i=0; i<size; i++)
		{
			*(vector+i)= 3;
		}
		int temp=0;
		#pragma omp for
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
			{
				temp=0;
				for(int k=0; k<size; k++)
				{
					temp += *(matrix+j*size+k) * *(vector+k);
				}
			}
			*(resVector+i) = temp;
		}
	}
	printf("\nFor size = %d\nDone in %f seconds\n", size, omp_get_wtime()-time);

	for(int i=0; i<size; i++)
	{
		printf(" %d ", resVector[i]);
	}
	return 0;
}

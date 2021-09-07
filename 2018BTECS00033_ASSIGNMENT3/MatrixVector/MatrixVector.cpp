#include<iostream>
#include<stdio.h>
#include<omp.h>

using namespace std;

int main()
{
	int size=0;
	printf("Enter size of matrix\n");
	scanf("%d", &size);
	omp_set_num_threads(10);
	int* matrix = new int[size*size];
	int* vector = new int[size];
	int* resVector = new int[size];
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
	double time = omp_get_wtime();
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
		printf("temp is %d\n", temp);
		*(resVector+i) = temp;
	}
	
	for(int i=0; i<size; i++)
	{
		printf(" %d ", resVector[i]);
	}
	
	printf("\nFor size = %d\nDone in %f seconds\n", size, omp_get_wtime()-time);
	return 0;
}

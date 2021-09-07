//#include<bits/stdc++.h>
#include <omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void static_schedule(int n,int chunk_size)
{
	int *a, *b, *c;
    	a=(int*)malloc(n*sizeof(int));
    	b=(int*)malloc(n*sizeof(int));
    	c=(int*)malloc(n*sizeof(int));
    
    	#pragma omp parallel for schedule(static, chunk_size) 
    	for(int i=0;i<n;i++)
    	{
    		a[i]= i;
    		b[i] = 2*i;
	}
	
	#pragma omp parallel for schedule(static, chunk_size)
	for(int i = 0 ;i < n;i++) {
		c[i] = a[i] + b[i];
	}
	
	free(a);
	free(b);
	free(c);
}

void dynamic_schedule(int n,int chunk_size)
{
	int *a, *b, *c;
    	a=(int*)malloc(n*sizeof(int));
    	b=(int*)malloc(n*sizeof(int));
    	c=(int*)malloc(n*sizeof(int));
    
   	#pragma omp parallel for schedule(dynamic, chunk_size)
    	for(int i=0;i<n;i++)
    	{
    		a[i]= i;
    		b[i] = 2*i;
  	}
	
	#pragma omp parallel for schedule(dynamic, chunk_size)
	for(int i = 0;i < n;i++) {
		c[i] = a[i] + b[i];
	}
	
	free(a);
	free(b);
	free(c);

	
}


int main() {

    	int n = 200;
	int chunk[] = {1,2,4,18,16};
	printf("\nStatic scheduling \n\n");
	while(n < 800000)
	{
		printf("\nfor vector size %d ",n);
		for(int i=0;i<5;i++)
		{
			clock_t t;
	    		t = clock();
	    		static_schedule(n,chunk[i]);
	    		t = clock() - t;
			double time_taken = ((double)t)/CLOCKS_PER_SEC;
			printf("\nfor chunck with size %d it will take time %f",chunk[i],time_taken);
		}
		printf("\n\n");
		n += n;
	}
	
	n = 200;
	printf("\n Dynamic scheduling \n\n");
	while(n < 80000)
	{
		printf("\nfor vector size %d ",n);
		for(int i=0;i<5;i++)
		{
			clock_t t;
	    		t = clock();
	    		dynamic_schedule(n,chunk[i]);
	    		t = clock() - t;
			double time_taken = ((double)t)/CLOCKS_PER_SEC;
			printf("\nfor chunck with size %d it will take time %f",chunk[i],time_taken);
		}
		printf("\n\n");
		n += n;
	}
	
}	
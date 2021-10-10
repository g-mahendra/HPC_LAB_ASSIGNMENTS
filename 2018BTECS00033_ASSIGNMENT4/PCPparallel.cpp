#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int full = 0;
int empty = 10, x = 0;

// create mutex lock variable
omp_lock_t mutex;

void producer()
{
	// set the mutex lock
	omp_set_lock(&mutex);
	if (empty == 0)
	{
		printf("Thread: %dBuffer is full!\n", omp_get_thread_num());
		omp_unset_lock(&mutex);
		return;
	}
	++full;

	--empty;

	x++;
	printf("Thread: %d produces item %d\n", omp_get_thread_num(), x);

	// unset the mutex lock
	omp_unset_lock(&mutex);
}

void consumer()
{
	// set the mutex lock
	omp_set_lock(&mutex);
	if (full == 0)
	{
		printf("Thread: %d Buffer is empty!\n", omp_get_thread_num());
		x = 0;
		omp_unset_lock(&mutex);
		return;
	}

	--full;

	++empty;
	printf("Thread: %d consumes item %d\n", omp_get_thread_num(), x);
	x--;

	// unset the mutex lock
	omp_unset_lock(&mutex);
}

int main()
{
	// initialize the mutex lock
	omp_init_lock(&mutex);
	omp_set_num_threads(8);
#pragma omp parallel
	{
		producer();
		consumer();
	}
	// remove the mutex lock
	omp_destroy_lock(&mutex);
}
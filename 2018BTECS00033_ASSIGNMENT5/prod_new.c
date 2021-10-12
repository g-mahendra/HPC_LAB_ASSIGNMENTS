#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MPI_Init(NULL, NULL);
    int size, rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int prod = 1;

    prod = arr[rank];

    int prod_main;
    MPI_Reduce(&prod, &prod_main, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);

    if (rank == 0)
        printf("Product of array elements is : %d\n", prod_main);

    MPI_Finalize();

    return 0;
}

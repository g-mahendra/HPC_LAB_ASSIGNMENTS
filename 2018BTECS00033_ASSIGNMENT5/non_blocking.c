#include <mpi.h>
#include <stdio.h>

int main()
{

    int first = 1, second = 2, third = 3, fourth = 4;

    MPI_Init(NULL, NULL);
    MPI_Request reqs[8];
    // int tags[2] = {1, 2};
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
        MPI_Isend(&first, 1, MPI_INT, 1, 20, MPI_COMM_WORLD, &reqs[0]);

    if (rank == 1)
    {
        MPI_Irecv(&first, 1, MPI_INT, 0, 20, MPI_COMM_WORLD, &reqs[1]);

        printf("process rank-  %d , data received %d \n", rank, first);

        MPI_Isend(&second, 1, MPI_INT, 2, 30, MPI_COMM_WORLD, &reqs[2]);
    }

    if (rank == 2)
    {
        MPI_Irecv(&second, 1, MPI_INT, 1, 30, MPI_COMM_WORLD, &reqs[3]);

        printf("process rank-  %d , data received %d \n", rank, second);

        MPI_Isend(&third, 1, MPI_INT, 3, 40, MPI_COMM_WORLD, &reqs[4]);
    }

    if (rank == 3)
    {
        MPI_Irecv(&third, 1, MPI_INT, 2, 40, MPI_COMM_WORLD, &reqs[5]);

        printf("process rank-  %d , data received %d \n", rank, third);

        MPI_Isend(&fourth, 1, MPI_INT, 0, 50, MPI_COMM_WORLD, &reqs[6]);
    }

    if (rank == 0)
    {

        MPI_Irecv(&fourth, 1, MPI_INT, 3, 50, MPI_COMM_WORLD, &reqs[7]);

        printf("process rank-  %d , data received %d \n", rank, fourth);
    }

    MPI_Finalize();
}

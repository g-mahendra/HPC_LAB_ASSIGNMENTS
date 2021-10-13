#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main()
{
    int numtasks, rank, prev, next, sendVal = 33, recVal, tag1 = 0, tag2 = 1, buf[2];

    MPI_Request reqs[4];
    MPI_Status stats[4];

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    prev = rank - 1;
    next = rank + 1;

    if (rank == 0)
        prev = numtasks - 1;
    if (rank == numtasks - 1)
        next = 0;

    MPI_Irecv(&buf[0], 1, MPI_INT, prev, tag1, MPI_COMM_WORLD, &reqs[0]);
    MPI_Irecv(&buf[1], 1, MPI_INT, prev, tag2, MPI_COMM_WORLD, &reqs[1]);

    MPI_Isend(&sendVal, 1, MPI_INT, next, tag2, MPI_COMM_WORLD, &reqs[2]);
    MPI_Isend(&sendVal, 1, MPI_INT, next, tag1, MPI_COMM_WORLD, &reqs[3]);

    PMPI_Waitall(2, reqs, stats);
    printf("Task %d interacted with taska %d and %d \n", rank, prev, next);

    MPI_Finalize();

    return 0;
}

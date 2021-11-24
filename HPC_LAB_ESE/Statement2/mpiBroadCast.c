#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int rank;
    int bufferValue = 0;
    int root = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == root)
    {
        bufferValue = 33;
    }

    printf("[%d]: Before broadcast, bufferValue is %d\n", rank, bufferValue);

    MPI_Bcast(&bufferValue, 1, MPI_INT, root, MPI_COMM_WORLD);

    printf("[%d]: After broadcast, bufferValue is %d\n", rank, bufferValue);

    MPI_Finalize();
    return 0;
}
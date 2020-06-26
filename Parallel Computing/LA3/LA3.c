#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int rank, numranks;

int is_prime(int n);

int main(int argc, char** argv){
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numranks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status stat;

    int n=1000000;
    int numprimes = 0;
    int start = 0;
    for (int i = 0; i < rank; i++) {
        start += ((int) (n / numranks)) + ((n % numranks > i) ? 1 : 0);
    }
    int end = start + ((int) (n / numranks)) + ((n % numranks > rank) ? 1 : 0);
    for (int i = start + 1; i <= end; i++)
    {
        if (is_prime(i) == 1)
            numprimes ++;
    }

    MPI_Allreduce(&numprimes, &numprimes, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    printf("Number of Primes: %d\n", numprimes);

    MPI_Finalize();

}

int is_prime(int n)
{
    /* handle special cases */
    if      (n == 0) return 0;
    else if (n == 1) return 0;
    else if (n == 2) return 1;

    int i;
    for(i=2;i<=(int)(sqrt((double) n));i++)
        if (n%i==0) return 0;

    return 1;
}

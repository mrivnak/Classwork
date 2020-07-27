#include "mpi.h"
#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "math.h"

double randomNum();

int main (int argc, char** argv){

    MPI_Init(&argc, &argv);
    int rank,numranks;
    MPI_Comm_size(MPI_COMM_WORLD,&numranks);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if (rank == 0)
        printf("\nNodes: %d\n", numranks);

    srand(time(NULL)+rank);
    unsigned long Ns[] = {240, 2400, 24000, 240000, 2400000, 24000000, 240000000, 2400000000};
    for (int i = 0; i < 8; i++) {
        unsigned long N = Ns[i];	// Total number of darts we will throw (read the assignment page)

        double start = MPI_Wtime();

        if(N % numranks != 0){
            if(rank == 0) {
                printf("N is not divisable by numranks: %ld %d\n",N, numranks);
            }
            MPI_Finalize();
            exit(1);
        }

        unsigned long hit;
        unsigned long myHit = 0;
        unsigned long myEles = N / numranks;  // how many elements/numbers each rank will try.  


        for (int i = 0; i < myEles; i++) {
            double x = randomNum();
            double y = randomNum();

            if ((x * x) + (y * y) <= 1) {
                myHit++;
            }
        }

        // printf("Rank: %d, i: %d, throws done: %f seconds\n", rank, i, MPI_Wtime() - start);

        MPI_Allreduce(&myHit, &hit, 1, MPI_UNSIGNED_LONG, MPI_SUM, MPI_COMM_WORLD);

        if(rank == 0){
            double pi = 4.0 * hit / N;
            printf("All reduce done: %f seconds\nN: %ld\nPi: %.10f\nError: %.10f\n", 
                MPI_Wtime() - start,
                N,
                pi,
                fabs(pi - acos(-1))
            );
        }
    }

    MPI_Finalize();
    return 0;
}

double randomNum(){

    //generates random number: [M,N]
    int M = -1;
    int N = 1;
    return (N - M) * (rand() / (double) RAND_MAX) + M;
}

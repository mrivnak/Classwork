#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	MPI_Init(&argc, &argv);
	int rank,numranks;
	MPI_Comm_size(MPI_COMM_WORLD,&numranks);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Status stat;
	int tag=0;

	// printf("numranks: %d, rank: %d\n", numranks, rank);

	int number=5;
	if (rank == 0) {
		MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Recv(&number, 1, MPI_INT, numranks-1, 0, MPI_COMM_WORLD,&stat);
		printf("Process 0 received number %d from process %d\n", number, numranks-1);
	} else {
		MPI_Recv(&number, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD,&stat);
		number +=1;
		MPI_Send(&number, 1, MPI_INT, rank == numranks-1 ? 0 : rank+1, 0, MPI_COMM_WORLD);
	}
	MPI_Finalize();
}
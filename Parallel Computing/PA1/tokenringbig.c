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

	const unsigned long int arraySize = 1024 * 1024 * 512;

	char * bigData = malloc(arraySize);
	double startTime = MPI_Wtime();

	if (rank == 0) {
		MPI_Send(bigData, arraySize, MPI_BYTE, 1, 0, MPI_COMM_WORLD);
		MPI_Recv(bigData, arraySize, MPI_BYTE, numranks-1, 0, MPI_COMM_WORLD,&stat);

		printf("Process 0 received data from process %d after %f ms\n", numranks-1, MPI_Wtime()-startTime);
	} else {
		MPI_Recv(bigData, arraySize, MPI_BYTE, rank-1, 0, MPI_COMM_WORLD,&stat);
		printf("Process %d received data from process %d after %f ms\n", rank, rank-1, MPI_Wtime()-startTime);
		MPI_Send(bigData, arraySize, MPI_BYTE, rank == numranks-1 ? 0 : rank+1, 0, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	free(bigData);
}

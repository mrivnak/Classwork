#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

#include "mvp.h"

int rank, numranks;

const unsigned int nodes = 5;
const unsigned int mult = 4;

//Main function
int main (int argc, char **argv) {
    const unsigned int size = nodes * mult;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numranks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status stat;

    double * matrix = allocMat(size, size);
    double * vector = allocVec(size);
    
    assignMat(matrix, size, size);
    assignVec(vector, size);
    
    double * result = mvp(matrix, vector, size);
    
    if (rank == 0) {
        printMatVec(matrix, vector, result, size, size);
    }

    MPI_Finalize();
    freeVec(vector);
    freeMat(matrix);
    return 0;
}

double* mvp(double* mat, double* vec, int n) {
    double * result = (double*) malloc(n*sizeof(double));

    double * data = (double*) malloc(mult*n*sizeof(double));
    MPI_Scatter(mat, n*mult, MPI_DOUBLE, data, n*mult, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // printf("Rank %d:\n", rank);
   
    for (int i = 0; i < mult; i++) {
        // printVec(data + (i*n), n);
    }

    double * resultPart = (double*) malloc(mult*sizeof(double));
    
    for (int i = 0; i < mult; i++) {
        resultPart[i] = dot(data + (i*n), vec, n);
    }

    // printf("Rank %d result:\n", rank);
    // printVec(resultPart, mult);
    
    MPI_Gather(resultPart, mult, MPI_DOUBLE, result, mult, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printVec(result, n);
    }
    return result;
}

double dot(double* a, double* b, int size) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += a[i] * b[i];
    }

    return result;
}

double* allocMat(int rows, int cols) {
	double* mat = (double*) malloc(rows*cols*sizeof(double));

    return mat;
}

double* allocVec(int size) {
    double* vec = (double*) malloc(size*sizeof(double*));
    return vec;
}

void assignMat(double* mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                mat[i+(j*cols)] = 2;
            }
            else if (i - j == 1 || j - i == 1) {
                mat[i+(j*cols)] = 1;
            }
            else {
                mat[i+(j*cols)] = 0;
            }
        }
    }
}

void assignVec(double* vec, int size) {
    for (int i = 0; i < size; i++) {
        vec[i] = 1;
    }
}

void freeMat(double* mat) {
    free(mat);
}

void freeVec(double* vec) {
    free(vec);
}

void printMatVec(double* mat, double* vec, double* res, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", mat[i+(j*cols)]);
        }
        printf("    %.2f   %c  %.2f\n", vec[i], i+1==((rows+(2-1))/2)?'=':' ', res[i]);
    }
}

void printMat(double* mat, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %.2f ", mat[i+(j*cols)]);
        }
        printf("\n");
    }
}


void printVec(double* vec, int size) {
    printf("Vector:\n");
    for (int i = 0; i < size; i++) {
        printf(" %.2f ", vec[i]);
    }
    printf("\n");
}

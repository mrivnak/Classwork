#include <stdio.h>
#include <stdlib.h>

#include "mvp.h"

//Main function
int main (int argc, char **argv) {
    const unsigned int size = 5;

    double ** matrix = allocMat(size, size);
    double * vector = allocVec(size);
    
    assignMat(matrix, size, size);
    assignVec(vector, size);
    
    double* result = mvp2(matrix, vector, size);

    printMatVec(matrix, vector, result, size, size);

    freeVec(vector);
    freeMat(matrix, size);
    return 0;
}

double* mvp2(double** mat, double* vec, int n) {
    double* result = (double*) malloc(n*sizeof(double));

    for (int i = 0; i < n; i++) {
        result[i] = dot(mat[i], vec, n);
    }

    return result;
}

double* mvp1(double* mat, double* vec, int n) {
    double* result = (double*) malloc(n*sizeof(double));

    for (int i = 0; i < n; i++) {
        result[i] = dot(mat + (n*i), vec, n);
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

double** allocMat(int rows, int cols) {
	double** mat = (double**) malloc(rows*sizeof(double*));

    for (int i = 0; i < rows; i++) {
        mat[i] = allocVec(rows);
    }

    return mat;
}

double* allocVec(int size) {
    double* vec = (double*) malloc(size*sizeof(double*));
    return vec;
}

void assignMat(double** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                mat[i][j] = 2;
            }
            else if (i - j == 1 || j - i == 1) {
                mat[i][j] = 1;
            }
            else {
                mat[i][j] = 0;
            }
        }
    }
}

void assignVec(double* vec, int size) {
    for (int i = 0; i < size; i++) {
        vec[i] = 1;
    }
}

void freeMat(double** mat, int rows) {
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }

    free(mat);
}

void freeVec(double* vec) {
    free(vec);
}

void printMatVec(double** mat, double* vec, double* res, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\t%.2f   %c  %.2f\n", vec[i], i+1==((rows+(2-1))/2)?'=':' ', res[i]);
    }
}

void printMat(double** mat, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %.2f ", mat[i][j]);
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

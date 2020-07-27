#include <stdlib.h>
#include <stdio.h>
//#define __USE_MISC
#include <math.h> 
#include <mpi.h>

extern int* imageToMat(char* name, int* dims);
extern void matToImage(char* name, int* mat, int* dims);
void createBFilter(double **bKernel,int size);
void createFilter(double **gKernel,int size);

int getMyRowStart(int size, int rank, int numranks);
int getMyRowEnd(int size, int rank, int numranks);

int main( int argc, char** argv ) {

    //initialize MPI
    MPI_Init(&argc, &argv);
    int rank,numranks;
    MPI_Comm_size(MPI_COMM_WORLD,&numranks);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    double fullstart=MPI_Wtime();

    int *matrix;
    char *name="/home/rivnakm/assignments/LA4/image.jpg";
    int *dims;
    dims=(int*) malloc(2*sizeof(int));

    /*
     * Assuming only Rank 0 has access to the image.
     */
    if(rank==0){
        matrix=imageToMat(name,dims);
    }

    /*
     * Bcast the dimensions of the image
     */
    MPI_Bcast(dims, 2, MPI_INT, 0, MPI_COMM_WORLD);


    int imageSize = dims[0] * dims[1];

    /*
     * Everyone else (except rank 0) must allocate space to store 
     * the image.
     */
    if(rank!=0){
        matrix = malloc(imageSize * sizeof(int));
    }

    MPI_Bcast(matrix, imageSize, MPI_INT, 0, MPI_COMM_WORLD);
    
    if(dims[1]%numranks!=0){
        if(rank==0){
            printf("height dim is not divisable by numranks: %d %d\n",dims[1],numranks);
        }
        MPI_Finalize();
        return 0;
    }

    /*
     * temp will be the size of the computed pixels for each rank
     */
    int *temp;
    int height = dims[0];
    int width = dims[1];

    // This supports images with an arbitrary number of rows but the matrix code doesn't yet
    int myRowStart = getMyRowStart(height, rank, numranks);
    int myRowEnd = getMyRowEnd(height, rank, numranks);

    printf("Rank: %d, start: %d, end: %d\n", rank, myRowStart, myRowEnd);

    int numrows = dims[0]/numranks;

    temp=(int*)malloc(numrows*width*sizeof(int));
    if(rank==0){
        printf("Total Dims %d %d\n",dims[0],dims[1]);
    }
    printf("Rank %d: myRowStart: %d myRowEnd: %d\n",rank,myRowStart,myRowEnd);

    //create gaussian filter on each rank
    //double gKernel[5][5];
    int size=51;
    int range=size/2;
    double *gKernel[size];
    for (int i=0;i<size;i++){
        gKernel[i]=(double *)malloc(size*sizeof(double));
    }
    createBFilter(gKernel,size);

    if(size<=5 && rank==0){ //then display filter
        for(int i = 0; i < size; ++i){
            for (int j = 0; j < size; ++j){
                printf("%5.2f  ",gKernel[i][j]);
            }
            printf("\n");
        }
    }

    double startTime = MPI_Wtime();

    //convolve
    double sum=0;
    int matval=0;
    for(int i=myRowStart;i<myRowEnd;i++){
        for(int j=0;j<width;j++){
            sum=0;
            int count=0;
            for(int ii=-range;ii<=range;ii++){
                for(int jj=-range;jj<=range;jj++){
                    if(i+ii<0 || j+jj<0 || i+ii>height-1 || j+jj>width-1){
                        //matval=127;
                    }else{
                        matval=matrix[(i+ii)*width+(j+jj)];
                    }
                    count++;
                    sum=sum+gKernel[ii+range][jj+range]*matval;
                }
            }

            temp[(i-myRowStart)*width+j]=sum;

        }
    }

    double endTime=MPI_Wtime();

    MPI_Gather(temp, width*numrows, MPI_INT, matrix, width*numrows, MPI_INT, 0, MPI_COMM_WORLD);

    double fullend=MPI_Wtime();

    printf("Rank %d: Compute Time: %5.2f\n",rank,endTime-startTime);

    //rank 0 writes image to file
    if(rank==0){

        printf("Full Time: %5.2f\n",fullend-fullstart);
        matToImage("/home/rivnakm/assignments/LA4/processedImage.jpg",matrix,dims);
    }
    MPI_Finalize();
    return 0;
}



void createBFilter(double **bKernel,int size){
    double sum=0.0;
    int range=size/2;
    // generate 5x5 kernel
    for (int x = -range; x <= range; x++){
        for(int y = -range; y <= range; y++){
            bKernel[x + range][y + range] = 1;
            sum += bKernel[x + range][y + range];
        }
    }
                                                                                             
    // normalize the Kernel
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            bKernel[i][j] /= sum;

}


void createFilter(double **gKernel,int size) { 
    int range=size/2;
    //set standard deviation to 1.0
    double sigma = 10.0;
    double r, s = 2.0 * sigma * sigma;

    // sum is for normalization
    double sum = 0.0;
                   
    // generate 5x5 kernel
    for (int x = -range; x <= range; x++){
        for(int y = -range; y <= range; y++){
            r = sqrt(x*x + y*y);
            gKernel[x + range][y + range] = (exp(-(r*r)/s))/(M_PI * s);
            sum += gKernel[x + range][y + range];
        }
    }
                                                                                             
    // normalize the Kernel
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            gKernel[i][j] /= sum;
}

int getMyRowStart(int size, int rank, int numranks) {
    int output = 0;

    for (int i = 0; i < rank; i++) {
        output += ((int) (size / numranks)) + ((size % numranks > i) ? 1 : 0);
    }

    return output;
}

int getMyRowEnd(int size, int rank, int numranks) {
    return getMyRowStart(size, rank, numranks) + ((int) (size / numranks)) + ((size % numranks > rank) ? 1 : 0);
}
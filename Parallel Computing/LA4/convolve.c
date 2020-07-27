#include <stdlib.h>
#include <stdio.h>
//#define __USE_MISC
#include <math.h>

extern int* imageToMat(char* name, int* dims);
extern void matToImage(char* name, int* mat, int* dims);
void createBFilter(double *bKernel[],int size);
void createFilter(double *gKernel[],int size);

int main( int argc, char** argv ) {
    int *matrix;
    int *temp;
    char *name="image.jpg";
    int *dims;
    dims=(int*) malloc(2*sizeof(int));

    matrix=imageToMat(name,dims);
    temp=(int*)malloc(dims[0]*dims[1]*sizeof(int));
    printf("Dims %d %d\n",dims[0],dims[1]);
    int height=dims[0];
    int width=dims[1];

    //create gaussian filter
    //double gKernel[5][5];
    int size=41;
    int range=size/2;
    double *gKernel[size];
    for (int i=0;i<size;i++){
        gKernel[i]=(double *)malloc(size*sizeof(double));
    }
    createBFilter(gKernel,size);

    if(size<=5){ //then display filter
        for(int i = 0; i < size; ++i){
            for (int j = 0; j < size; ++j){
                printf("%5.2f  ",gKernel[i][j]);
            }
            printf("\n");
        }
    }

    //convolve
    double sum=0;
    int matval=0;
    for(int i=0;i<height;i++){
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

            
            temp[i*width+j]=sum;

        }
    }

    matToImage("processedImage.jpg",temp,dims);
    return 0;
}


void createBFilter(double *bKernel[],int size){
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

void createFilter(double *gKernel[],int size){
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

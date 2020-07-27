#include "mpi.h"
#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "math.h"

double randomNum();

int main (int argc, char** argv){

    srand(time(NULL));

}

double randomNum(){

    //generates random number: [M,N]
    int M=-1;
    int N=1;
    return (N-M)*(rand()/(double)RAND_MAX)+M;
}

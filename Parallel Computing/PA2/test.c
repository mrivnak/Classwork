#include <stdio.h>

int main() {
    int numranks = 8;
    int N = 20;

    for (int i = 0; i < numranks; i++) {
        printf("%d",((int) (N / numranks)) + ((N % numranks > i) ? 1 : 0));
    }
    printf("\n");
}
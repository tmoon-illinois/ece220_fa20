#include <stdio.h>
#include <stdlib.h>

int main(){

    int *ptr = malloc(4*sizeof(int));

    *ptr = 100;
    ptr[1] = 10;
    ptr[2] = 100;

    printf("%d\n", *ptr);

    free(ptr);
}


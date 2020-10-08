#include <stdio.h>
#define SIZE 5
int binarySearch(int array[], int l, int r, int key);

int main(){
    int array[SIZE] = {1, 4, 9, 10, 20};
    int index = binarySearch(array, 0, SIZE-1, 8);

    printf("found at index %d\n", index);

}


int binarySearch(int array[], int low, int high, int key){
    int L, H, M;
    L = low;
    H = high;



    while(L<=H)
    {
        M = (L+H)/2;
        if(key < array[M])
            H = M-1;
        else if(key > array[M])
            L = M+1;
        else
            return M;
    }
    return -1;
}

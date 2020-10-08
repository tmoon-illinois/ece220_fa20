#include <stdio.h>
#define SIZE 5

void array_reverse(int array[], int n);
void print_array(int array[], int n);
int main(){

    int arr[SIZE] = {1,2,3,4,5};

    print_array(arr, SIZE);
    array_reverse(arr, SIZE);
    print_array(arr, SIZE);

}
void array_reverse(int array[], int n){
    int i;
    int temp;

    //
    for(i=0; i< n/2;i++){
        temp = array[i];
        array[i] = array[n-i-1];
        array[n-i-1] = temp;
    }

}
void print_array(int array[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ", array[i]);
    printf("\n");
}


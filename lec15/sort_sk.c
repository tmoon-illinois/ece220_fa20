#include <stdio.h>
#define SIZE 7
void print_array(int array[], int n);
void swap(int *firstVal, int *secondVal);
void bubbleSort(int array[], int n);
void insertSort(int array[], int n);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);

int main()
{
    //int array[SIZE] = {64, 34, 25, 12, 22, 11, 1};
    //int array[SIZE] = {5, 1, 4, 2, 8};
    //int array[SIZE] = {95, 1, 84, 22, 80};
    int array[SIZE] = {50, 80, 30, 90, 40, 10, 70};

    printf("Before sort: ");
    print_array(array, SIZE);
    
    
    //bubbleSort(array, SIZE);
    //insertSort(array, SIZE);
    quickSort(array, 0, SIZE-1);


    printf("After sort: ");
    print_array(array, SIZE);

}
void print_array(int array[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}
void swap(int *firstVal, int *secondVal){
    int tempVal;

    tempVal = *firstVal;
    *firstVal = *secondVal;
    *secondVal = tempVal;
}
// n: size of array
void bubbleSort(int array[], int n)
{
    int is_swap, i;

    do{
        is_swap = 0;
        for(i=0;i<n-1;i++){
            if( array[i] > array[i+1]){
                swap(&array[i], &array[i+1]);
                is_swap = 1;
            }
        }
    }while(is_swap!=0);

}
void insertSort(int array[], int n)
{
    int unsorted;   // Index for unsorted list items
    int sorted;     // Index for sorted items
    int unsortedItem;   // Current item to be sorted

    // Loop from 1 thru n
    for(unsorted = 1; unsorted <n; unsorted++){
        unsortedItem = array[unsorted];
        // Loop from unsorted-1 thru 0
        // if unsortedItem < current sorted item, shift the current item to the right
        // stop if we hit a smaller element than unsortedItem
        sorted = unsorted -1;
        while( array[sorted] > unsortedItem && sorted >= 0 ){
            array[sorted+1] = array[sorted];
            sorted--;

        }
        array[sorted+1] = unsortedItem;
    }

}

int partition(int array[], int low, int high){
    int pivot = array[high];
    int i = low-1;
    int j;

    for(j=low; j<=high-1; j++){
        if(array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[high]);
    return i+1;
}
void quickSort(int array[], int low, int high){
    if(low>=high)
        return;
    else{
        int pivot_index = partition(array, low, high);
        printf("%d\n", pivot_index);
        quickSort(array, low, pivot_index-1);
        quickSort(array, pivot_index+1, high);
    }
}





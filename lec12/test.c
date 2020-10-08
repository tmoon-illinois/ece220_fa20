#include <stdio.h>
#define MAX_NUM 10
//int func(int array[]);
//int func(int *array);
int func(int array[MAX_NUM]);

int main(){
    int array[MAX_NUM] = {1,2,3};
    int result;

    result = func(array);

    printf("%d\n", result);
}
int func(int array[MAX_NUM]){
    return array[0];
}


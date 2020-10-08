#include <stdio.h>
#define SIZE_BUF 100
void print(int *a);
void print2D(int a[][3]);
int main(){
    /*
    char buf1[SIZE_BUF] = "ABC";
    char buf2[SIZE_BUF] = "DEF";
    char buf3[SIZE_BUF] = "123";


//    fgets(buf2, SIZE_BUF, stdin);

    scanf("%3s", buf2);
    printf("%s %s %s\n", buf1, buf2, buf3);
    */
    int array[2][3] = {{1,2,3},{4,5,6}};

    print(&(array[0][0]));
    print2D(array);
}

void print(int *a){
    printf("%d\n", a[1*3+1]);
    printf("%d\n", *(a + 1*3 + 1));
}
void print2D(int a[][3]){
    printf("%d\n", a[1][1]);
}

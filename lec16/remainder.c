#include <stdio.h>
#define BUF_SIZE 6
int main(){
    char buf1[BUF_SIZE];
    char buf2[BUF_SIZE];

    printf("Enter 4 digits (** **): ");
    fgets(buf1, BUF_SIZE, stdin);
    printf("%s\n", buf1);

    getchar();
    
    printf("Enter 4 digits (** **): ");
    fgets(buf2, BUF_SIZE, stdin);
    printf("%s\n", buf2);
    
}

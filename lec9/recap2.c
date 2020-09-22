#include <stdio.h>

int main(){
    int i,j;
    int n=3;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                printf("1 ");
                if(j==1)
                    break;
            }
            else
                printf("0 ");
        }

        if(i==1)
            break;
        printf("\n");

    }
    /*
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==1 && i==1 ){
                printf("1 ");
                return 0;
            }
            else if(i==j)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
    */

}

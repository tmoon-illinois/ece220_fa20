#include <stdio.h>

int main(){
    /*
    int x;

    for(x=0;x<10;x++)
        printf("%d ", x);
    

    printf("\n");

    for(x=0;x<10;++x)
        printf("%d ", x);
*/


    int x,y;

    for(x=0;x<5;x++){
        for(y=0;y<5;y++){
            if(y==2)
                break;
            printf("%d %d\n", x,y);
        }
    }

}


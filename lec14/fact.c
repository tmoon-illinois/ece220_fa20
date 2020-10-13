#include <stdio.h>

int Factorial_iter(int n){
    int i;
    int result= 1;
    for(i=1;i<=n;i++){
        result = result * i;
    }

    return result;
}

int Factorial(int n){
    if(n==1)
        return 1;
    else
        return n*Factorial(n-1);
}

int main(){
    printf("%d\n", Factorial_iter(4));
    printf("%d\n", Factorial(4));
}

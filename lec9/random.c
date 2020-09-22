#include <stdio.h>
#include <stdlib.h>

double GenRand(double a, double b);
int main(){

    int seed;

    printf("Enter a seed integer: ");
    scanf("%d", &seed);

    srand(seed);


    printf("%lf\n", GenRand(0, 1));
    printf("%lf\n", GenRand(0, 1));
    printf("%lf\n", GenRand(0, 1));
    printf("%lf\n", GenRand(0, 1));
    printf("%lf\n", GenRand(0, 1));

}

double GenRand(double a, double b){
    int num = rand();// [0, RAND_MAX] -> [a,b]

    double result;

//    result = (double) (num/RAND_MAX)*(b-a) + a;
    result =  (1.0*num/RAND_MAX)*(b-a) + a;
    //result =  (num/RAND_MAX)*(b-a) + a;

    return result;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_a_dice1(int *one, int *two, int *three);
void roll_a_dice2(int array[]);

int main(){
/*
    int seed;
    printf("Enter a seed: ");
    scanf("%d", &seed);
    srand(seed);
*/
    srand(time(0));
    int rnd[3];

    printf("%p\n", rnd);
    printf("%p\n", &rnd);

    roll_a_dice1(&rnd[0], &rnd[1], &rnd[2]);
    //roll_a_dice2(rnd);
    //rnd[0] = 1;

    printf("%d %d %d\n", rnd[0], rnd[1], rnd[2]);
}
void roll_a_dice1(int *one, int *two, int *three){
    one = (rand()%6) + 1;
    *two = (rand()%6) + 1;
    *three = (rand()%6) + 1;
}

void roll_a_dice2(int array[]){
    array[0] = (rand()%6) + 1;
    array[1] = (rand()%6) + 1;
    array[2]  = (rand()%6) + 1;
}


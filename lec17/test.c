#include <stdio.h>
#include <string.h>

enum weekday {SUN = 10, MON, TUE=14, WED};
struct flightType{
    char name[20];//20
    int a;//4
    float b;//4
    int c;//4
    char s;//1
};//33
typedef struct flightType Flight;


typedef union Union1{
    char c;
    int x;
    double y;
}union1;

int main(){
    Flight plane[10];
    Flight *ptr;


    printf("%d %d\n", sizeof(int*), sizeof(Flight*));
    printf("%d %d\n", sizeof(int), sizeof(Flight));

//    plane[0].name = "AAA"; // error
    strcpy(plane[0].name, "AAA");

    printf("%s, %d, %f, %d\n", plane[0].name, plane[0].a, plane[0].b, plane[0].c);
/*

    printf("%d %d %d \n", sizeof(char), sizeof(int), sizeof(float));

    printf("%d\n", sizeof(Flight));

    enum weekday today;

    today = WED;
    printf("%d\n", today);
    today = MON;
    printf("%d\n", today);

    union1 u1;

    u1.c = 'a';
    u1.x = 1;
    u1.y = 1.1;

    printf("%c %d %lf\n", u1.c, u1.x, u1.y);
*/

}

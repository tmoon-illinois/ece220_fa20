#include <stdio.h>
//#include <string.h>

void string_copy(char des[], const char src[]);
int main(){
    char buf[200];
    char src[200] = "ABCD";


    char temp[100] = "abcdef";
/*
    printf("%s", &temp[2]);
    temp[3] = '\0';
    printf("%s", temp);
    
//    buf = "ABC";

    //strcpy(buf, "ABC");
 */  
    //scanf("%s", src);
    //printf("%s\n", src);

    fgets(src, 200, stdin);
    printf("%s\n", src);
  /* 
    string_copy(buf, src);
    printf("%s\n", buf);
    printf("%s\n", src);
    */
}


//void string_copy(char *des, char *src){
void string_copy(char des[], const char src[]){
    int i=0;
    while( src[i] != '\0' ){
        des[i] = src[i];
        i++;
    }
    //src[0] = '1';

    des[i] = '\0';
}

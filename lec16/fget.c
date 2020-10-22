#include <stdio.h>

int main(){
    FILE *fp1, *fp2;

    fp1 = fopen("file1", "r");
    if(fp1 == NULL){
        printf("No file1\n");
        return 1;
    }
    fp2 = fopen("file2", "w");

    char c;
    c = fgetc(fp1);
    fputc(c, fp2);
    c = fgetc(fp1);
    fputc(c, fp2);
    fclose(fp1);
    fclose(fp2);
}

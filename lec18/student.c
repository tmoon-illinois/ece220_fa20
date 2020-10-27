#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 100
typedef struct StudentStruct{
    int UIN;
    //char netid[BUF_SIZE];
    char *netid;
    float GPA;
}student;

int loadFile(char filename[], student **s);
void printStudents(student s[], int num);
void swapStudent(student *s1, student *s2);
void sortGPA(student *s, int num);
int main(){
    //student s[100];
    student *s;

    int numStudent;
    char filename[20];
    printf("Enter file name: ");
    scanf("%s", filename);

    numStudent = loadFile(filename, &s);
    printStudents(s, numStudent);
    
//    sortGPA(s, numStudent);
//    printStudents(s, numStudent);
//

    int i;
    for(i=0;i<numStudent;i++)
        free(s[i].netid);
    free(s);
    return 0;
}
//int loadFile(char *filename, student *s){
// return the number student in the file
int loadFile(char filename[], student **s){
    FILE *fp;

    if( (fp = fopen(filename, "r")) == NULL){
        printf("Cannot open %s.\n", filename);
        return -1;
    }

    char buffer[BUF_SIZE], buffer_name[BUF_SIZE];
    int num = 0;

    fgets(buffer, BUF_SIZE, fp);//skip header

    student *temp = NULL;
    student *more= NULL;

    while( (fgets(buffer, BUF_SIZE, fp)) !=NULL){
        more = realloc(temp, sizeof(student)*(num+1));
        if(more != NULL)
            temp = more;
        else{
            printf("Not enough memory\n");
            return -1;
        }
        sscanf(buffer, "%d %s %f", &(temp[num].UIN), buffer_name , &(temp[num].GPA));
        temp[num].netid = malloc( strlen(buffer_name)+1);
        strcpy(temp[num].netid, buffer_name);
        num++;
    }

    *s = temp;

    fclose(fp);

    return num;

}
void printStudents(student s[], int num){
    int i;
    printf("UIN netid GPA\n");
    for(i=0;i<num;i++)
        printf("%d %s %f\n", s[i].UIN, s[i].netid, s[i].GPA);

}
void swapStudent(student *s1, student *s2){
    student temp;

    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
void sortGPA(student *s, int num){
    int is_swap, i;

    do{
        is_swap = 0;
        for(i=0;i<num-1;i++){
            if( s[i].GPA < s[i+1].GPA){
                swapStudent(&s[i], &s[i+1]);
                is_swap = 1;
            }
        }
    }while(is_swap!=0);
}

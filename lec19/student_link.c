#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 100
typedef struct StudentStruct{
    int UIN;
    char *netid;
    float GPA;
    struct StudentStruct *next;
}node;

void insert_head(node **headpptr, node *data);
void insert_sorted_GPA(node **headpptr, node *data);
int loadFile(char filename[], node **headpptr);
void printStudents(node *headptr);
void delete_all(node **headptr);
int delete_node(node **headpptr, int UIN);

int main(){
    node *headptr = NULL;

    int numStudent, uin;
    char filename[20];


    node data;
    data.UIN = 1;
    data.netid = malloc(sizeof("AAA")+1);
    strcpy(data.netid, "AAA");
    data.GPA = 1.0;

    insert_sorted_GPA(&headptr,&data);


    //second
    data.UIN = 2;
    data.netid = malloc(sizeof("BBB")+1);
    strcpy(data.netid, "BBB");
    data.GPA = 2.0;
    insert_sorted_GPA(&headptr,&data);

    //third
    data.UIN = 3;
    data.netid = malloc(sizeof("BBB")+1);
    strcpy(data.netid, "CCC");
    data.GPA = 1.5;
    insert_sorted_GPA(&headptr,&data);

    printStudents(headptr);

/*    
    printf("Enter file name: ");
    scanf("%s", filename);

    numStudent = loadFile(filename, &headptr);
    printStudents(headptr);

    printf("Enter UIN to delete: ");
    scanf("%d", &uin);
    if(delete_node(&headptr, uin)==0) printf("cannot delete UIN %d\n", uin);
    printStudents(headptr);

    delete_all(&headptr);
    printStudents(headptr);
*/
    return 0;

}
void insert_head(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;
    temp->next = *headpptr;
    *headpptr = temp;
}
// descending order sort by GPA
void insert_sorted_GPA(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;
    while(*headpptr &&  (*headpptr)->GPA > data->GPA) 
        headpptr = &((*headpptr)->next);

    temp->next = *headpptr;
    *headpptr = temp;
}
int loadFile(char filename[], node **headpptr){
    FILE *fp;
    if((fp = fopen(filename, "r")) == NULL){
        printf("Cannot open %s.\n", filename);
        return -1;
    }
    char buf[BUF_SIZE], buf_name[BUF_SIZE];
    int num= 0;
    fgets(buf, BUF_SIZE, fp); //skip the header

    node data;
    while(fgets(buf, BUF_SIZE, fp)){ //NULL if fails
        sscanf(buf, "%d %s %f", &(data.UIN), buf_name, &(data.GPA));
        data.netid = malloc(strlen(buf_name)+1);
        strcpy(data.netid, buf_name);
        insert_head(headpptr, &data);
        //insert_sorted_GPA(headpptr, &data);
        num++;
    }
    fclose(fp);
    return num;
}

void printStudents(node *headptr){
    printf("UIN netid GPA\n");
    while(headptr){
        printf("%d %s %f\n", headptr->UIN, headptr->netid, headptr->GPA);
        headptr = headptr->next;
    }
}
void delete_all(node **headpptr){
    node *next;
    while(*headpptr){
        printf("deleting %s\n", (*headpptr)->netid);
        free((*headpptr)->netid);
        next = (*headpptr)->next;
        free(*headpptr);
        *headpptr = next;
    }
    *headpptr = NULL;
}
// if UIN found, delete the node and return 1
// else return 0
int delete_node(node **headpptr, int UIN){
    node *target;
    while(*headpptr && (*headpptr)->UIN != UIN)
        headpptr = &((*headpptr)->next);

    if(*headpptr == NULL) return 0;
    target = *headpptr;
    *headpptr = target->next;
    free(target->netid);
    free(target);
    return 1;
}

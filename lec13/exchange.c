#include <stdio.h>
#define M 2
#define N 3
void matrix_change(int matrix[M][N], int x, int y);
void matrix_print(int matrix[M][N]);
void matrix_print2(int matrix[N][M]);
void matrix_tr(int des[N][M], int src[M][N]);
int main(){
    int array[M][N] = {{1,2,3},{4,5,6}};
    int des[N][M];

    matrix_print(array);
    matrix_tr(des, array);
    //matrix_change(array, 0, 1);
    matrix_print(array);
    matrix_print2(des);



}
void matrix_tr(int des[N][M], int src[M][N]){
    int i,j;

    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
            des[j][i] = src[i][j];
}

void matrix_change(int matrix[M][N], int x, int y){
    int temp, i;

    for(i=0;i<N;i++){
        temp = matrix[x][i];
        matrix[x][i] = matrix[y][i];
        matrix[y][i] = temp;
    }
}
void matrix_print(int matrix[M][N]){
    int i,j;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
void matrix_print2(int matrix[N][M]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

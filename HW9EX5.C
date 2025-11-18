#include<stdio.h>
#include<stdlib.h>
int main(){
    int rows , cols;
    printf("\nEnter number of rows:");
    scanf("%d",&rows);
    printf("\nEnter number of column:");
    scanf("%d",&cols);
// Allocation of the row pointers
int** array =(int**) malloc(rows * sizeof(int*));
if(array==NULL){
    printf("Memory allocation failed.\n");
}
// Allocation of each rows
for (int i = 0; i < rows;i++) {
    array[i] = (int*)malloc(cols * sizeof(int));
    if(array==NULL){
    printf("Memory allocation failed.\n");
}
    for(int j=0;j<cols;j++){
        printf("\nEnter student ID at row %d, column %d: ",i,j);
        scanf("%d",&array[i][j]);
    }
   }
   printf("Seating chart:\n");
   for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        printf("%d ",array[i][j]);
    }
    printf("\n");
   }
// Deallocation
for (int i = 0; i < rows; i++) {
    free(array[i]);
}
free(array);
return 0;
}
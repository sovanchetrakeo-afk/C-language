#include<stdio.h>
#include<stdlib.h>
int main(){
    int rate;
    printf("How many  ratings will you enter?");
    scanf("%d",&rate);
    printf("You can rate from 1 to 10\n");
    int* rating =(int*)malloc(rate*sizeof(int));
    if(rating==NULL){
        printf("Fail");
    }
    for(int i=1;i<=rate;i++){
        printf("Enter rating #%d: ",i);
        scanf("%d",&rating[i]);
    }
    printf("Ratings entered: ");
    for(int i=1;i<=rate;i++){
       printf("%d ",rating[i]);
    }
    free(rating);
    return 0;
}
  
    
   




#include<stdio.h>
#include<string.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
 
}
int main() {
   int x,y;
   printf("Enter the first value : ");
   scanf("%d", &x);
   printf("Enter the second value: ");
    scanf("%d",&y);
    
    printf("Before  the swap:\n x = %d   (address=%p)\n y = %d  (address=%p)\n", x, &x,y,&y);
    
    swap(&x, &y);
    
    printf("After the  swap:\n x = %d  (address=%p)\n y = %d   (address=%p)\n", x,&x, y,&y);
    
    return 0;
}
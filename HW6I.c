#include<stdio.h>
#include<math.h>
void logg(int *a, int size) {
    printf("The elements of the array are:\n");
    for(int i=0; i<size; i++) {
    printf("\narray[%d] = %d(Address:%p)\n ", i ,*(a+i),(a+i));
    }
}
int main() {
    int size;
    int arr[size];
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elments of the array:\n");
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    int *ptr = arr;
    logg(ptr, size);
    
    return 0;
}
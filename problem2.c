#include <stdio.h >
int main ()  {
    int arr[] ={0,7,2,3,4};
    int temp;
    temp =arr[0];
    arr[0] = arr[1];
    arr[1] =temp;
    
    for (int i=0 ; i<5 ; i++) {
        printf( "%d", arr[i]);
    }return 0;
}
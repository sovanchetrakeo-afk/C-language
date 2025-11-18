#include<stdio.h>
#include<string.h>
void reverseString(char str[]){
    int n = strlen(str);
    for(int i=0; i<n;i++){
        char temp = str[i];
        str[i]=str[n-1];
        str[n-1]=temp;
        n--;
    }
    
}
int main(){
   char tex[]="CADT";
   reverseString(tex);
   printf("Reversed string: %s\n", tex);
    return 0;
}
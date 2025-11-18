#include<stdio.h>
#include<string.h>
int lengthOf(const char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}
int main(){
    printf("Enter your name: "); 
    char str[100];
    scanf("%[^\n]", str); 
    int size= lengthOf(str);
    printf("Your name has %d characters \n", size);
    return 0;
}
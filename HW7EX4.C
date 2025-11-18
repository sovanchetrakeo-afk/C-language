#include<stdio.h>
#include<string.h>
int countVowels(const char* str){
    int count =0;
    while(*str != '\0'){
        if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' || *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U') {
            count++;
        }
        str++;
    }
    return count;
}
int main(){
    printf("Enter a string: ");
    char str[100];
    scanf("%[^\n]", str);
    int vowelCount = countVowels(str);
    printf("Number of vowels: %d\n", countVowels(str));
    return 0;
}
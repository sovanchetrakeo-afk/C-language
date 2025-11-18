#include<stdio.h>
#include<string.h>
#include<ctype.h>
void toUpper(char* str){
    while(*str != '\0'){
        *str = toupper(*str);
        str++;
    }
}
int main(){
char text[]="Roman is the best!";
toUpper(text);
printf("Uppercase string: %s\n", text);
return 0;

}
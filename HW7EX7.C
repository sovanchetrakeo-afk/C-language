#include<stdio.h>
#include<string.h>
int parseInt(const char* str){
    int intValue=0;
    for(int i=0;i<10;i++){
        if(str[i] >= '0' && str[i] <= '9'){
            intValue =  intValue*10 + (str[i] - '0');
        }else if(str[i] == '\0'){
            break;
        }
 }
    return intValue;
}
int main(){
    const char* str = "1597";
    int result = parseInt(str);
    printf("%d\n", result);
    return 0;
 }

    
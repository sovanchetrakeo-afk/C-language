#include<stdio.h>
#include<string.h>
void printInitial(const char* str){
    int len = strlen(str);
for(int i = 0; i < len; i++){
        if((i == 0 || str[i-1] == ' ')&&((str[i]>='A'&&str[i]<='Z'))){
            printf("%c.",str[i]);
        }
        if(str[i]==' ') {
            printf("");
        }
        
    } 
if(str[0]>='a'&&str[0]<='z'){
    for(int j=0;j<len;j++){
        if(str[j]>='a'&&str[j]<='z'){
            printf("%c.",str[j]-32);
        }
    } 
}

}
int main(){
    const char* str= " ";
    printInitial(str);
    return 0;
}
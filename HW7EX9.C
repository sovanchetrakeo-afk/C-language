#include<stdio.h>
int my_strcmp(const char *s1, const char  *s2){
    for(int i=0;i<10;i++){
        if(s1[i]==s2[i]){
            continue;
        }else if(s1[i]<s2[i]){
            return -1;
        }else if(s1[i]>s2[i]){
            return 1;
        }else if(s1[i]==' '&&s2[i]==' '){
            return 0;
        }else if('a'>=s1[i]<='z'&&s2[i]==' '){
            return 1;
        }else if(s1[i]==' '&&'a'>=s2[i]<='z'){
            return -1;
        }
    }
    return 0; 
}
int main(){
    const char *s1="banana";
    const char *s2="bank";
    int result =my_strcmp(s1,s2);
    printf("%d",result);
    return 0;
}

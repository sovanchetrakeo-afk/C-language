#include<stdio.h>
#include<string.h>
typedef struct{
   int hour;
   int minute;
   int second;
}Time;
Time time1;
Time time2;
Time sumtime(Time time1,Time time2){
    Time r;
    int sumH=0;
    int sumM=0;
    int sumS=0;
    sumH=time1.hour+time2.hour;
    sumM=time1.minute+time2.minute;
    if(sumM>60){
        sumH++;
        sumM=sumM-60;
    }
    sumS=time1.second+time2.second;
    if(sumS>60){
        sumM++;
        sumS=sumS-60;
    }
    r.hour=sumH;
    r.minute=sumM;
    r.second=sumS;
   
    return r;
    
}
int CompareTime(Time time1,Time time2){
    if(time1.hour>time2.hour){
        return 1;
    }else if(time2.hour>time2.hour){
        return -1;
    }else if((time1.hour==time2.hour)&&(time1.minute>time2.minute)){
       return 1;
    }else if((time1.hour==time2.hour)&&(time1.minute<time2.minute)){
       return -1;
    }else if((time1.hour==time2.hour)&&(time1.second==time2.second)&&(time1.second>time2.second)){
       return 1;
    }else if((time1.hour==time2.hour)&&(time1.second==time2.second)&&(time1.second<time2.second)){
       return -1;
    }
     return 0;
}
int main(){
    Time time1={1,45,00};
    Time time2={1,30,00};
    printf("time1:{%d,%02d,%02d}\n",time1.hour,time1.minute,time1.second);
    printf("time2:{%d,%02d,%02d}\n",time2.hour,time2.minute,time2.second);
    printf("The sun of 2 times");
    Time r=sumtime(time1,time2);
    printf("{%d,%02d,%02d}\n",r.hour,r.minute,r.second);
    int result=CompareTime(time1,time2);
    printf("Result is:%d",result);
    return 0;

}
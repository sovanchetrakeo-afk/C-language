#include<stdio.h>
#include<string.h>
typedef struct{
   int hour;
   int minute;
   int second;
}Time;
typedef struct{
   char name[50];
   Time time; 
}Attendance;
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
Attendance getLatest(Attendance attendance[5]){
    Attendance latest=attendance[4]; // to assign for  preparing other 
    for(int i=0;i<4;i++){
        if(CompareTime(attendance[i].time,latest.time)==1){
            latest=attendance[i];
        }  
    }
     return latest;
}
int main(){
    Attendance att[5]={ {"Nick",{2,20,00}},
                        {"Alex",{2,25,00}},
                        {"Taylor",{2,30,00}},
                        {"Nak",{1,52,45}},
                        {"Barron",{1,20,00}},
    };
    Attendance late=getLatest(att);
    printf("The lates student is:%s", late.name);
    return 0;
}
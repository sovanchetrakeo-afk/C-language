#include<stdio.h>
#include<string.h>
typedef struct{
  char arrName[50];
  int  ID;
  float arrScore[5];
}Student;
Student viseth;
Student sousdey;

double getScoreAverage(Student student,int size){
    float sum=0;
    for(int j=0;j<size;j++){
         sum += student.arrScore[j];
    } 
    return sum/size;  
}
int main(){
    Student info[2]={
        {"Viseth",110244,{88,84,85,86,87} },
        {"Sousdey",110245,{87,88,89,90,92}},
    };
    
    for(int i=0;i<2;i++){
        printf("Student:%s\n",info[i].arrName);
        printf("ID:%d\n",info[i].ID);
        printf("Score:\n");
        for(int j=0;j<5;j++){
        printf("%.2f\n",info[i].arrScore[j]);
        }
        double average = getScoreAverage(info[i],5);
        printf("Average=%.2f\n",average);
    }
return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char name[50];
    int salary;
} Employee;
int main(){
    Employee* employee=(Employee*)malloc(2*sizeof(Employee));
    if(employee==NULL){
        printf("Failed\n");
    }
    for(int i=0;i<2;i++){
        printf("Enter name and salary for employee %d:",i+1);
        scanf("%s %d",&employee[i].name,&employee[i].salary);
    }
    Employee* newemployee=(Employee*)realloc(employee,5*sizeof(Employee));
    if(newemployee==NULL){
        printf("Failed\n");
        free(employee);
    } 
    free(newemployee);
    for(int i=2;i<5;i++){
        printf("Enter name and salary for employee %d:",i+1);
        scanf("%s %d",&newemployee[i].name,&newemployee[i].salary);
    }
   for(int i=0;i<5;i++){
    printf("Employee %d-> name: %s salary: %d\n",i+1,employee[i].name,employee[i].salary);
   }
   free(employee);
   return 0;
}
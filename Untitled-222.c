#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int getRandomInRange(int min ,int max){
    return min+rand() % (max-min+1);
}
int attack(){
    return getRandomInRange(5,12);
}
int heal(){
    return getRandomInRange(8,15);
}
int specialAttack(){
    return getRandomInRange(8,25);
}
int monsterAttack(){
    return getRandomInRange(8,12);
}
void printStatus(int knightlife , int monsterlife) {
    printf("Knight  HP: %d\n " ,knightlife);
    printf("Monster HP: %d\n", monsterlife);
}
void printRoundLog(int KnightDamage , int monsterDamage){
    printf("You attacked the monster and dealt %d damage. \n",KnightDamage);
    printf("The monster attacked and dealt %d damage. \n", monsterDamage);

}
int main(){
   srand(time(NULL));  // Seed the random number generator
   int Knightlife=20;  // Knight's life
   int monsterlife=20; // Monster's life
   int round =1;       // The round index 
   char choice;
   while (Knightlife>0&&monsterlife>0) {
    printf("\n--Round %d--\n",round);
    printf("Choose Action: (A) Attack (H) Heal (S) Special Attack \n ");
    printf(">");
    scanf(" %c", &choice);
    if (choice =='A'){
       int KnightDamage =attack();
       int monsterDamage = monsterAttack();
         monsterlife -= KnightDamage;
            Knightlife -= monsterDamage;
            printRoundLog(KnightDamage, monsterDamage);
            printStatus(Knightlife, monsterlife);
            
    } 
     else if (choice =='S'){
        int specialAttackDamage = specialAttack();
        monsterlife -= specialAttackDamage;
        printf("You used a special attack and dealt %d damage to the monster.\n", specialAttackDamage);
        int monsterDamage = monsterAttack();
        Knightlife -= monsterDamage;
        printf("The monster attacked and dealt %d damage. \n", monsterDamage);
        printStatus(Knightlife, monsterlife);
    
} else if (choice =='H'){
        int healAmount = heal();
        int monsterDamage = monsterAttack();
        Knightlife += healAmount;
        if (Knightlife > 20) {
            Knightlife = 20; // Cap the healing to max HP
        }
        Knightlife -= monsterDamage;
        printf("You healed yourself for %d points.\n", healAmount);     
        printf("The monster attacked and dealt %d damage. \n", monsterDamage);
        printStatus(Knightlife, monsterlife);}
round++;
} 
if (Knightlife <= 0) {
    printf(" You have been defeated by the monster.\n");
} else if (monsterlife <= 0) {
    printf("Victory! You defeated the monster!\n");
} else if (Knightlife <= 0 && monsterlife <= 0) {
    printf("It's a draw! Both you and the monster have fallen.\n");
} else if(Knightlife <monsterlife ) {
    printf("You have been defeated by the monster.\n");
} else if(Knightlife >  monsterlife ) {
    printf("Victory! You defeated the monster!\n");
} else {
    printf("Game over!\n");
    
}
return 0;
}

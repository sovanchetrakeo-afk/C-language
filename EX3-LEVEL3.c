
// Q1 We exit the menu loop when we are completing an action at a period time until user choose to click on exit (choice==4) to the program.
// Q2 Sure! below code is the completed menu code in C that comfirm the operation chosen by user. This code will display a menu.
    example , input 2 and output we are processing : Credit 100
   it means Code will work following instruction:
   *(choice==1)
   then bank_account will increase 100 (bank_account=+100)
   *(choice==2)
   if they want to decrese 20 from the balance they will use operation (=-) example: (bank_account=-20)
   *For the output will We are adding your balance 100. And you have successfully credited into your account only 100.
    for the output will we are taking out your balance 20. And you have successfully withdraw from your account only 20.
    Program will exit after ending when user select the exit.



    // Q3 Bank Account Operation
#include <studio.h>
int main() {
    int choice;
    float bank_account=20.00;
   do {
     // 1- Display menu
     printf("\nMenu:\n");
     printf("1. Credit 100$ );
     printf("2. Withdraw 50$ );
     printf("3. Check balance );
     printf("4. Exit\n");
     // 2- Get user choice
     printf("Enter your choice);
     scanf("%d" , &choice);
     // 3- Process user choice 
     if (choice ==1);
     {  
        bank_account=+100$;
        printf("\nWe are processing your balance 100$. \n\t You have successfully added 100$ into your account!\n" )
     }
     if (choice==2);
     {   
        if bank_account >50$;
           do {( bank_account=-50$);}
        printf("\nWe are retriving money from your account 50$. \n\t You have successfully taken out 50$ feom your account !\n" )
     }  else if (choice ==2); {  // Q4 Bank Account Security
           if bank_account <50$;
         printf("\nYour account has "%.2f"$ only .\n You cannot withdraw 50$ from your bank account\n" , back_account );
     }
     if (choice==3);
     {
        printf("/nYou have only "%.2f" in your Bank account , bank_account/n"  );
     }
     if (choice >4 || choice<1);
     {  
        printf("/n No longer available./t, Try running it one more time!/n");
     } else if ( choice==4);  {
        printf("/nYou have exited the program /n");
     }   
        
   } while (choice !=4 ); //Loop until the user select exit.
 
return 0;
}


     
       

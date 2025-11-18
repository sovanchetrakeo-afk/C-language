#include <stdio.h>
int main () {
    int year1=2002 ;
    int month1=6;
    int day1=7;
    int year2=2002;
    int month2=6;
    int day2=1;
    printf( " your date of birth of  person1:"%d" /"%d"/"%d"   " , year1/month1/day1 );
    scanf ("%d" , &year1);
    printf ("your date of bith of person2 : "%d"/"%d"/"%d"  "  , year2/month2/day2);
    scanf("%d" , &year2);
    if (year1 > year2) {
        printf("The second person is the youngest"  );

    } else if (year1 < year2){
        printf (" The first person is the youngest" );
        printf (" First person is born on June 7th ,2002 - Second person is born on June  1st ,2002")
    } return 0;

}
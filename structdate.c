#include<stdio.h>
struct date
{
    int day;
    int month;
    int year;
};

int main()
{
    struct date d1,d2;
    
    printf("ENTER FIRST DATE\n");
    printf("DAY=");
    scanf("%d",&d1.day);
    printf("MONTH=");
    scanf("%d",&d1.month);
    printf("year=");
    scanf("%d",&d1.year);

    printf("ENTER SECOND DATE\n");
    printf("DAY=");
    scanf("%d",&d2.day);
    printf("MONTH=");
    scanf("%d",&d2.month);
    printf("year=");
    scanf("%d",&d2.year);

    if(d1.day > d2.day)
    {
        if(d1.month > d2.month)
        {
            if(d1.year > d2.year)
                printf("EARLIER DATE=%d/%d/%d",d2.day,d2.month,d2.year);
            else
                printf("EARLIER DATE=%d/%d/%d",d1.day,d1.month,d1.year);
               
        }
    }
    else if(d1.day < d2.day)
    {
        if(d1.month < d2.month)
        {
            if(d1.year < d2.year)
                printf("EARLIER DATE=%d/%d/%d",d1.day,d1.month,d1.year);
            else
                printf("EARLIER DATE=%d/%d/%d",d2.day,d2.month,d2.year);
        }
    }
    else 
        printf("BOTH ARE SAME DATE");

    return 0;
}
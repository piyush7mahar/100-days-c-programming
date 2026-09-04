#include<stdio.h>
int main()
{
    int year;
    printf("ENTER ANY YEAR:");
    
    
    if (scanf("%d",&year)==1)
    {
        if (year%400==0 || (year%4==0 && year%100!=0))
        {
            printf("IT IS A LEAP YEAR");
        }else 
        {
            printf("NOT A LEAP YEAR");
        }
        
    }else
    {
        printf("INVALID VALUE");
    }

}
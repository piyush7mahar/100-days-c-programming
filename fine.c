#include<stdio.h>
int main()
{
    int days,fine;
    printf("ENTER NUMBER OF DAYS=");
    scanf("%d",&days);

    if (days<0)
    {
        printf("INVALID.");
    }else if (days<=5)
    {
        fine=days*2;
        printf("FINE=RS.%d",fine);
    }else if (days<=10)
    {
        fine=((5*2) + (days-5)*4);
        printf("FINE=RS.%d",fine);

    }else if (days<=30)
    {
        fine=((5*2) + (5*4) + (days-10)*6);
        printf("FINE=RS.%d",fine);
    }else 
    {
        printf("MEMBERSHIP CANCELLED.");
    }
    return 0;
}


#include<stdio.h>
int main()
{
    float units,bill;
    printf("ENTER UNITS USED=");
    scanf("%f",&units);

    if (units<0)
    {
        printf("INVALID.");
    }else if (units<=100)
    {
        bill=units*5;
        printf("ELECTRICITY BILL=RS.%f",bill);
    }else if (units<=200)
    {
        bill=((100*5) + (units-100)*7);
        printf("ELECTRICITY BILL=RS.%f",bill);

    }else if (units<=300)
    {
        bill=((5*100) + (100*7) + (units-200)*10);
        printf("ELECTRICITY BILL=RS.%f",bill);
    }else 
    {
        bill=((5*100) + (100*7) + (units-300)*12);
        printf("ELECTRICITY BILL=RS.%f",bill);
    }
    return 0;
}
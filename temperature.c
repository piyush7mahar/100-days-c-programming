//Write a program to convert temperature from Celsius to Fahrenheit.
#include <stdio.h>
int main() 
{
    int c;
    printf("ENTER TEMPERATURE IN CELSIUS=");
    scanf("%d",&c);

    int f;
    f=c*(9/5)+32;
    printf("TEMPERATURE IN FAHRENHEIT=%d",f);

    return 0;
}
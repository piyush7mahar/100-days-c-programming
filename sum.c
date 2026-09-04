//Write a program to input two numbers and display their sum

#include<stdio.h>
int main()
{
    int a;
    printf("ENTER NUMBER 1 =");
    scanf("%d",&a);

    int b;
    printf("ENTER NUMBER 2 =");
    scanf("%d",&b);

    int sum;
    sum=a+b;
    printf("SUM OF BOTH NUMBERS=%d",sum);

    return 0;

}
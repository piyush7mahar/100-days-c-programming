//Write a program to swap two numbers using a third variable.

#include<stdio.h>
int main()
{
    int a;
    printf("ENTER a=");
    scanf("%d",&a);

    int b;
    printf("ENTER b=");
    scanf("%d",&b);

    // before swapping 
    printf("a=%d\n",a);
    printf("b=%d\n",b);

    int c;
    //swapping numbers using c;
    printf("AFTER SWAPPING:");
    c=a;
    a=b;
    b=c;
    // after swapping;
    printf("a=%d\n",a);
    printf("b=%d\n",b);

    return 0;
    

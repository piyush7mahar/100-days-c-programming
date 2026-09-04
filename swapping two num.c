//Write a program to swap two numbers using a third variable.

#include<stdio.h>
int main()
{
    int a;
    printf("ENTER a=");

    int b;
    printf("ENTER b=");

    printf("a=%d",a);
    printf("b=%d",b);

    int c;
    //swapping numbers using c;

    c=a;
    a=b;
    b=c;
    // after swapping;
    printf("a=",a);
    printf("b=",b);

    return 0;
    


}
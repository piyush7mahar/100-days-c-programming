//	Write a program to swap the first and last digit of a number.

#include <stdio.h>
int main()
{
    int n;
    printf("ENTER A NUM=");
    scanf("%d",&n);

    int first,last,i,a=1;
    i=n;
    last=n%10;
    while (i>=10)
    {
        i=i/10; 
        a=a*10;
    }
    first=i;

    n=n-first*a-last;
    n=n+last*a+first;

    printf("SWAPPED NUMBER=%d",n);
    return 0;
}
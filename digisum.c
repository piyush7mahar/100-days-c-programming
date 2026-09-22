//	Write a program to find the sum of digits of a number.
#include <stdio.h>
int main()
{
    int n;
    printf("ENTER A NUM=");
    scanf("%d",&n);

    int digit=0;
    int sum=0;
    while(n!=0)
    {
        digit=n%10;
        sum=sum+digit;
        n=n/10;
    }
    printf("sum of digit of the num=%d",sum);
    return 0;
}
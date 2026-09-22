//	Write a program to find the product of odd digits of a number.

#include <stdio.h>
int main()
{
    int n;
    printf("ENTER A NUM=");
    scanf("%d",&n);

    int digit;
    int sum=0;
        while(n!=0){
            digit=n%10;
            if (digit%2!=0)
            {
                sum=sum+digit;
            }
            n=n/10;
        }
        printf("SUM=%d",sum);

    return 0;
}
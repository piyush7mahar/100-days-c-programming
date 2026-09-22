//Write a program to check if a number is a perfect number.

#include<stdio.h>
int main()
{
    int n;
    printf("ENTER A NUMBER=");
    scanf("%d",&n);

    int i=1;
    int a;
    int sum=0;
    while(i<n)
    {
        a=n%i;
        if (a==0)
        {
            sum=sum+i;
        }
        
        i++;
    }
    if (sum==n)
    {
        printf("ITS A PERFECT NUMBER=%d",n);
        
    }else
        printf("NOT A PERFECT NUMBER");
    return 0;
}
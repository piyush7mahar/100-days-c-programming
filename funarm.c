#include<stdio.h>
int countDigits(int n);
int power(int base, int exponent);
int isArmstrong(int n);

int main()
{
    int num;
    printf("ENTER A NUMBER=");
    scanf("%d",&num);

    int final;
    final=isArmstrong(num);

    if(final==1)
        printf("IT IS AN ARMSTRONG");
    else if (final==0)
        printf("NOT");
    
    return 0;
}
int countDigits(int n)
{
    int c=0;
    while(n>0)
    {
         n=n/10;
         c++;
    }
    return c;
}
int power(int base,int exponent)
{
        int i,result=1;

        for(i=1;i<=exponent;i++)
            result=result*base;
        return result;
}
int isArmstrong(int n)
{
    int i;
    int sum=0;
    int n1=n;
    int digit;
    int count=countDigits(n);
    int final;
    for(i=1;i<=count;i++)
    {
        int a;
        digit=n1%10;
        sum=sum+power(digit,count);
        n1=n1/10;
    }

    if(sum==n)
        final=1;
    else
        final=0;
    
    return final;
}
//	Write a program to find the 1’s complement of a binary number and print it.
#include <stdio.h>
int main()
{
    int n;
    printf("ENTER A BINARY NUM=");
    scanf("%d",&n);

    int digit;
    int result=0;
    int i=1;

    while(n!=0)
    {
        digit=n%10;
        if (digit==0)
            digit=1;
        else if (digit==1)
            digit=0;
        else
            printf("not valid");

        result=result+digit*i;
        i=i*10;
        n=n/10;
    }
    printf("COMPLEMENT OF BINARY NUM=%d",result);
    return 0;
}



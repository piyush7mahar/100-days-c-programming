//Find the digit that occurs the most times in an integer number.

#include<stdio.h>

int main()
{
    int n, digit;
    int c[10]={0};
    int max=0,maxdigit=0;

    printf("Enter a number: ");
    scanf("%d",&n);

    while(n>0)
    {
        digit=n%10;
        c[digit]++;
        n = n / 10;
    }
    for(int i=0;i<10;i++)
    {
        if(c[i]>max)
        {
            max=c[i];
            maxdigit=i;
        }
    }

    printf("Most occurring digit=%d",maxdigit);
    return 0;
}
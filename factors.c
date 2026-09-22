//Write a program to print all factors of a given number.

#include<stdio.h>
int main()
{
    int n;
    printf("ENTER A NUMBER=");
    scanf("%d",&n);

    int i=1;
    while(i<=n)
    {
        if (n%i==0)
        {
            printf("FACTORS=%d\n",i);
            
        }

        i++;
    }
    return 0;
                    
}
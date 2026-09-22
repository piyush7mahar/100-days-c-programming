//Write a program to check if a number is prime.

#include<stdio.h>
int main()
{
    int n;
    printf("ENTER ANY NUMBER=");
    scanf("%d",&n);

    for(int i=2;i<=n;i++)
        if (n%i==0)
        {
            printf("IT NOT A PRIME NUMBER.");
            break;
        }
        else 
        {
            printf("IT IS A PRIME NUMBER.");
            break;
        }
    return 0;        
}

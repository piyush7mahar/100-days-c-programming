//Write a program to find the LCM of two numbers.

#include<stdio.h>
int main()
{
    int num1;
    printf("ENTER NUMBER1=");
    scanf("%d",&num1);

    int num2;
    printf("ENTER NUMBER2=");
    scanf("%d",&num2);

    int i=1;
    int lcm;
    while(1)
    {
        if(i%num1==0&&i%num2==0)
        {
            lcm=i;
            break;
        }
        i++;

    }
    
    printf("LCM=%d",lcm);

    return 0;

}
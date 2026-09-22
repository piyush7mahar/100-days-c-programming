//	Write a program to find the HCF (GCD) of two numbers.

#include<stdio.h>
int main()
{
    int num1;
    printf("ENTER NUMBER 1=");
    scanf("%d",&num1);
    
    int num2;
    printf("ENTER NUMBER 2=");
    scanf("%d",&num2);


    int i=1;
    int hcf;
    while(i<=num1 && i<=num2)
    {
        if(num1%i==0&&num2%i==0){
            hcf=i;
        }
    i++;

    }
    
    printf("HCF=%d",hcf);
    return 0;
}
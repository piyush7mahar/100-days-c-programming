//Write a program to input two numbers and display their sum, difference, product, and quotient

#include<stdio.h>
int main()
{
    int a;
    printf("ENTER NUMBER 1 =");
    scanf("%d",&a);

    int b;
    printf("ENTER NUMBER 2 =");
    scanf("%d",&b);

    int sum;
    sum=a+b;
    printf("SUM=%d\n",sum);

    int diff;
    diff=a-b;
    printf("DIFFERENCE=%d\n",diff);

    int product;
    product=a*b;
    printf("PRODUCT=%d\n",product);

    int quo;
    if (b==0)
    {
        printf("QUOTIENT =0");
    }else 
    {
        quo=a/b;
        printf("QUOTIENT=%d",quo);
    }
    

    return 0;
}
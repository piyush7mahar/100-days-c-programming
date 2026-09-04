//Write a program to input an integer and check whether it is even or odd using if–else

#include<stdio.h>
int main()
{
    int num;
    printf("ENTER ANY INTEGER=");
    scanf("%d",&num);

    if (num==0)
    printf("IT IS ZERO");
    else if (num%2==0 && num!=0)
    printf("IT IS AN EVEN NUMBER");
    else 
    printf("IT IS AN ODD NUMBER");
    
    return 0 ;
}
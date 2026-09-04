//Write a program to calculate the area and perimeter of a rectangle given its length and breadth

#include<stdio.h>
int main()
{
    int l;
    printf("ENTER LENGTH=");
    scanf("%d",&l);

    int b;
    printf("ENTER BREADTH=");
    scanf("%d",&b);

    int p;
    p=2*(l+b);
    printf("PERIMETER=%d\n",p);

    int a;
    a=l*b;
    printf("AREA=%d",a);

    return 0;


}
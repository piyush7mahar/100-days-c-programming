//Reverse an array without taking extra space.

#include<stdio.h>
int main()
{
    int a[4]={1,2,3,4};
    int n,i;
    for( i=0;i<2;i++)
    {   n=a[i];
        a[i]=a[3-i];
        a[3-i]=n;
    }
    printf("REVERSED ARRAY:\n");
    for( i=0;i<=3;i++)
        printf("%d",a[i]);
    
    return 0;
    
}

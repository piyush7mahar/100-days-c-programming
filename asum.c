//	Find the sum of array elements.

#include<stdio.h>
int main()
{
    int a[4]={1,2,3,4};
    
    printf("SUM OF ELEMENTS OF ARRAY=");
    int sum=0;
    for(int i=0;i<=3;i++)
    {
        sum=sum+a[i];
    }    
    printf("%d",sum);
    return 0;
}
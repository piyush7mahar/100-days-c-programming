//	Search in a sorted array using binary search.

#include<stdio.h>

int main()
{
    int a[6]={1,2,3,4,6};
    int n=5;
    int p=4;
    int i;
    for(i=5;i>=p;i--)
        a[i]=a[i-1];
    printf("NEW ARRAY-");
    a[p]=n;
    for(i=0;i<=5;i++)
        printf("%d ",a[i]);

    return 0;
}
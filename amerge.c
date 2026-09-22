//Merge two arrays.

#include<stdio.h>
int main()
{
    int a[4]={1,2,3,4};
    int b[4]={5,6,7,8};
    int c[6];
    int i;

    for(i=0;i<=4;i++)
        c[i]=a[i];
    for(i=0;i<=4;i++)
        c[i+3]=b[i];
    
    printf("MERGED ARRAY=");
    for(i=0;i<=6;i++)
        printf("%d",c[i]);

    return 0;
}
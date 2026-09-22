//Read and print elements of a one-dimensional array.

#include<stdio.h>
int main()
{
    int a[4]={1,2,3,4};
    
    printf("ELEMENTS OF ARRAY\n");
    for(int i=0;i<=3;i++)
        printf("%d\n",a[i]);

    return 0;
}
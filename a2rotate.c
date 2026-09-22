#include <stdio.h>

int main()
{
    int a[5] = {1,2,3,4,5};
    int b[5];
    int i,k=2;

    for(i=0;i<5;i++)
        b[(i+k)%5]=a[i];

    for(i=0;i<5;i++)
        a[i] = b[i];

    printf("Rotated array=");

    for(i = 0; i < 5; i++)
        printf("%d ",a[i]);
    

    return 0;
}
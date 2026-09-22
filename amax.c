//	Find the maximum and minimum element in an array.

#include<stdio.h>
int main()
{
    int a[4]={1,2,3,4};

    int m=a[0];
    int n=a[0];
    for(int i=0;i<=3;i++)
    {
        if (a[i]>m)
            m=a[i];
        else if (a[i]<n)
            n=a[i];
    }
    printf("MAXIMUM ELEMENT=%d\n",m);
    printf("MINIMUM ELEMENT=%d\n",n);
    return 0;
}
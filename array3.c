//Find the second largest element in an array.

#include <stdio.h>

int main()
{
    int a[5] = {1,2,3,4,5};
    int l,s,i ;

    l=a[0];
    s=a[0];

    for(i=1;i<5;i++)
    {
        if(a[i]>l)
        {
            s=l;
            l=a[i];
        }
        else if(a[i]>s)
        {
            s=a[i];
        }
    }

    printf("Second largest = %d", s);

    return 0;
}
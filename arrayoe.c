//	Count even and odd numbers in an array.

#include<stdio.h>
int main()
{
    int a[4]={1,2,3,4};
    int ce=0;
    int co=0;
    for(int i=0;i<=3;i++)
    {
        if (a[i]%2==0)
            ce++;
        else if (a[i]=0)
            printf("zero value");
        else
            co++;
    }
    printf("EVEN ELEMENTS=%d\n",ce);
    printf("ODD ELEMENTS=%d\n",co);

    return 0;
}
    
    


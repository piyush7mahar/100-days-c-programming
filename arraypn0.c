//	Count positive, negative, and zero elements in an array.

#include<stdio.h>

int main()
{
    int a[6]= {-2,-1,0,1,2,0};
    int p=0,n=0,zero=0;

    for(int i=0;i<6;i++)
    {
        if(a[i]>0)
            p++;
        else if(a[i]<0)
            n++;
        else
            zero++;
    }

    printf("Positive = %d\n", p);
    printf("Negative = %d\n", n);
    printf("Zero = %d\n", zero);

    return 0;
}









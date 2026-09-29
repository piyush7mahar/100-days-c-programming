//	Perform diagonal traversal of a matrix.

#include <stdio.h>
int main()
{
    int a[3][3]={1,2,3,4,5,6,7,8,9};

    int i,j,x;

    for(x=0;x<=4;x++)
    {
        for(i=0;i<3;i++)
        {
            j=x-i;
            if(j>=0&&j<3)
                printf("%d ",a[i][j]);
        }
        
        printf("\n");
    }

    return 0;
}
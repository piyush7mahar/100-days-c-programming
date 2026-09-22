//	Find the sum of each row of a matrix and store it in an array.

#include <stdio.h>

int main()
{
    int a[3][3] = {1,2,3,4,5,6,7,8,9};
    int row[3] = {0};
    int i, j;

    for(i = 0;i<3;i++)
    {
        for(j = 0; j < 3; j++)
        {
            row[i]=row[i]+a[i][j];
        }
    }

    for(i=0;i<3;i++)
    {
        printf("Sum of row=%d\n",row[i]);
    }

    return 0;
}
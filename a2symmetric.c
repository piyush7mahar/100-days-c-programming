//Check if a matrix is symmetric.

#include<stdio.h>
int main()
{
    int a[3][3]={1,2,3,2,4,6,3,6,9};
    int f=0;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if (a[i][j]==a[j][i])
                f=1;
        }
    
    if(f==1)
        printf("MATRIX IS SYMMETRIC");
    else 
        printf("NOT SYMMETRIC");

    return 0;
}
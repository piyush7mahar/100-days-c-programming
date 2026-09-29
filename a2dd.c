//	Check if the elements on the diagonal of a matrix are distinct.

#include<stdio.h>
int main()
{
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    int f=0;

    for(int i=0;i<3;i++)
        for(int j=i+1;j<3;j++)
        {
            if (a[i][i]==a[j][j])
                f=1;
        }
    
    if(f==1)
        printf("DIAGONAL ELEMENTS ARE SAME");
    else 
        printf("DIAGONAL ELEMENTS ARE DISTICT");

    return 0;
}


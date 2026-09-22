//	Find the sum of all elements in a matrix.

#include<stdio.h>
int main()
{
	int a[2][3]={1,2,3,4,5,6};

	printf("PRINTING THE MATRIX:");

	int i;
	int j;
    int sum=0;
	for(i=0;i<=1;i++)
    {
        for(j=0;j<=2;j++)
            {
                sum=sum+a[i][j];
            }
        }

    printf("SUM OF ALL ELEMENTS=%d",sum);
	return 0;

}
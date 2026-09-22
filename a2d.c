//Read and print a matrix.

#include<stdio.h>
int main()
{
	int a[2][3]={1,2,3,4,5,6};

	printf("PRINTING THE MATRIX:");

	int i;
	int j;
	for(i=0;i<=1;i++)
	{
		for(j=0;j<=2;j++)
	        printf("%d ",a[i][j]);
	}

	return 0;

}
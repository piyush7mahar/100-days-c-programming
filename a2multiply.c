//Multiply two matrices.

#include<stdio.h>
int main()
{
	int a[2][2]={1,2,3,4};
	int b[2][2]={2,4,6,8};
	int i,j;
    int m[2][2]={};
	for(i=0;i<2;i++)
	    for(j=0;j<2;j++)
		{
			m[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j];
			
		}
	printf("MATRIX\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		    printf("%d ",m[i][j]);
	    printf("\n");
	}
	return 0;
}
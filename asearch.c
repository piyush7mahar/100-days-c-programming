//Search for an element in an array using linear search.

#include<stdio.h>
int main()
{
    int a[4]={1,2,3,4};
	int s,f=0;
	printf("ELEMENT YOU WANT TO SEARCH=");
	scanf("%d",&s);
    int i;
	for(i=0;i<=3;i++)
	{
		if (s==a[i])
		{   
			f=1;
			break;
		}
	}
	if (f=1)
	    printf("ELEMENT AT INDEX=%d",i);
	
	else 
		printf("NOT FOUND");
		return 0;
}
//Delete an element from an array.
#include <stdio.h>

int main()
{
    int a[5]={1,2,3,4,5};
    int p=3;
    int i;

	printf("BEFORE REMOVING ELEMENT:");
	for(i=0;i<5;i++)
	    printf("%d ",a[i]);
	    printf("\n");

    for(i=p-1;i<4;i++)
	    a[i]=a[i+1];
    
	printf("AFTER REMOVING ELEMENT:");
    for(i=0;i<4;i++)
        printf("%d ",a[i]);

    return 0;
}




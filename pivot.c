#include<stdio.h>
int main()
{
    int n;
    
    printf("ENTER THE NUMBERS OF ELEMETS=");
    scanf("%d",&n);

    int arr[n];
    printf("ENETER THE ELEMENTS OF ARRAY=");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("ARRAY-");
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");

    int pivot=-1;
    
    for(i=0;i<n;i++)
    {
        int j;
        int leftsum=0;
        int rightsum=0;

        for(j=0;j<i;j++)
        {
            leftsum=leftsum+arr[j];
        }
        for(j=i;j<n;j++)
        {
            rightsum=rightsum+arr[j];
        }
        if(rightsum==leftsum)
        {
            pivot=i;
            break;
        }
    }
    printf("PIVOT INDEX=%d", pivot);
    return 0;
}
#include<stdio.h>
int subsum(int arr[],int n,int k);
int main()
{
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS=");
    scanf("%d",&n);

    int arr[n];
    printf("ENTER ELEMENTS OF ARRAY=");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("ARRAY=");
    for(int i=0;i<n;i++)
        printf(" %d",arr[i]);
    
    printf("\n");
    int k;
    printf("ENTER THE NUMBER OF ELEMENTS OF SUBSTRING=");
    scanf("%d",&k);
    
    subsum(arr,n,k);
    return 0;
}
int subsum(int arr[],int n,int k)
{
    int j;
    int found=0;
    for( int i=0;i<=n-k;i++)
    {
        for(j=i;j<i+k;j++)
        {
            if (arr[j]<0)
            {
                printf("%d ",arr[j]);
                found=1;
                break;
            }
        }
        if(found==0)
            printf("0");
    }
}

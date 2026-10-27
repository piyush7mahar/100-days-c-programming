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
    int maxsum=0;
    int j;
    for( int i=0;i<=n-k;i++)
    {
        int sum=0;
        for(j=i;j<i+k;j++)
        {
            sum=sum+arr[j];
        }
        if(i==0 || sum>maxsum)
            maxsum=sum;
    }
    printf("MAXIMUM SUM OF THE SUBARRAY IS=%d",maxsum);
}

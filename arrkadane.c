#include <stdio.h>

int maxSubarray(int arr[],int n);

int main()
{
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS=");
    scanf("%d",&n);

    int arr[n];
    printf("ENTER ELEMENTS OF ARRAY=");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("ARRAY=");
    for (int i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }

    printf("\n");

    maxSubarray(arr,n);

    return 0;
}
int maxSubarray(int arr[],int n)
{
    int sum = arr[0];
    int maxsum = arr[0];

    for(int i=1;i<n;i++)
    {
        if(sum+arr[i]>arr[i])
            sum = sum + arr[i];
        else
            sum = arr[i];
        if (sum > maxsum)
            maxsum = sum;
    }
    printf("MAXIMUM SUM=%d", maxsum);
}
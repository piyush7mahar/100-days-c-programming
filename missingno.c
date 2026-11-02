#include <stdio.h>

int missingNumber(int arr[], int n);

int main()
{
    int n;

    printf("ENTER THE SIZE OF ARRAY=");
    scanf("%d", &n);

    int arr[n];

    printf("ENTER THE ELEMENTS OF ARRAY=");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int missing = missingNumber(arr, n);

    printf("MISSING NUMBER=%d", missing);

    return 0;
}

int missingNumber(int arr[], int n)
{
    int sum = 0;
    int actualsum = 0;

    for(int i=0;i<=n;i++)
        sum=sum+i;

    for(int i=0;i<n;i++)
        actualsum = actualsum+arr[i];

    return sum-actualsum;
}
#include <stdio.h>
int repeatedNumber(int arr[], int n);
int main()
{
    int n;
    printf("ENTER THE SIZE OF ARRAY=");
    scanf("%d",&n);

    int arr[n];
    printf("ENTER THE ELEMENTS OF ARRAY=");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    repeatedNumber(arr, n);
    return 0;
}

int repeatedNumber(int arr[], int n)
{
    int repeat;
    int arraysum=0;
    int expectedsum=0;
    
    for(int i=0;i<n;i++)
    {
        arraysum=arraysum+arr[i];
        
        if(i<n-1)
        expectedsum=expectedsum+(i+1);
    }
    repeat=arraysum-expectedsum;
    printf("REPEATED ELEMENT=%d", repeat);
}
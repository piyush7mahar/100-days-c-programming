#include <stdio.h>
int ksmallest(int arr[],int n,int k);
int main()
{
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS=");
    scanf("%d",&n);

    int arr[n];
    printf("ENTER ELEMENTS OF ARRAY=");
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("ARRAY=");
    for (int i=0;i<n;i++)
        printf(" %d",arr[i]);
    printf("\n");

    int k;
    printf("ENTER K=");
    scanf("%d",&k);

    ksmallest(arr,n,k);
    return 0;
}
int ksmallest(int arr[],int n,int k)
{
    int temp;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Kth SMALLEST ELEMENT=%d", arr[k-1]);
}
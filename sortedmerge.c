#include<stdio.h>
int sortedmerge(int arr1[],int arr2[],int n,int m);
int main()
{
    int n;
    printf("ENTER THE ELEMENTS OF NUMS=");
    scanf("%d", &n);

    int arr1[n];
    printf("ENTER THE ELEMENTS IN SORTED MANNER =");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    printf("ELEMENTS OF NUMS=");
    for (int i = 0; i < n; i++)
        printf("%d", arr1[i]);

    printf("\n");

    int m;
    printf("ENTER THE ELEMENTS OF NUMS=");
    scanf("%d", &m);

    int arr2[m];
    printf("ENTER THE ELEMENTS IN SORTED MANNER=");

    for (int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    printf("ELEMENTS OF ARR2=");
    for (int i = 0; i < m; i++)
        printf("%d", arr2[i]);

    printf("\n");
    sortedmerge(arr1,arr2,n,m);

    return 0;

}
int sortedmerge(int arr1[],int arr2[],int n,int m)
{
    int c[m+n];
    int i=0,j=0,k=0;

    while(i<m && j<n)
    {
        if(arr1[i]<arr2[j])
        {
            c[k]=arr1[i];
            i++;
        }
        else
        {
            c[k]=arr2[j];
            j++;
        }
        k++;
    }

    while(i<m)
    {
        c[k]=arr1[i];
        i++;
        k++;
    }

    while(j<n)
    {
        c[k]=arr2[j];
        j++;
        k++;
    }
    printf("MERGED ARRAY=");

    for(int i=0;i<m+n;i++)
        printf("%d ", c[i]);
}
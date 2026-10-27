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

    int x;
    printf("ENTER ANY NUMBER=");
    scanf("%d",&x);

    int index=-1;
    for(i=0;i<n;i++)
    {
        if(arr[i]>=x)
        {   index=i;
            break;
        }
    }
    printf("%d",index);
    return 0;
}

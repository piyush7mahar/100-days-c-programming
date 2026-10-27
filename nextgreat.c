#include<stdio.h>
int main()
{
    int n;
    
    printf("ENTER THE NUMBERS OF ELEMENTS=");
    scanf("%d",&n);

    int nums[n];
    printf("ENTER THE ELEMENTS OF ARRAY=");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    printf("ARRAY-");
    for(i=0;i<n;i++)
    {
        printf("%d",nums[i]);
    }
    printf("\n");

    for(i=0;i<n;i++)
    {
        int j;
        int next=-1;
        for(j=i+1;j<n;j++)
        {
            if(nums[j]>nums[i])
                next=nums[j];
                break;
        }
        printf("%d",next);

        if(i<n-1)
            printf(",");
    }
    return 0;
    }
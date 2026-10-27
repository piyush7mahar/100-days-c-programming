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

    int majority=-1;
    for(i=0;i<n;i++)
    {
        int count=0;
        int j;
        for(j=0;j<n;j++)
        {
            if(nums[i]==nums[j])
            count++;
        }
        
        if (count>n/2)
        majority=nums[i];
    }
    printf("MAJORITY NUMBER=%d",majority);
    return 0;

}
#include <stdio.h>
int sumequaltarget(int nums[],int n ,int target);
int main()
{
    int n;
    printf("ENTER THE ELEMENTS OF NUMS=");
    scanf("%d", &n);

    int nums[n];
    printf("ENTER THE ELEMENTS OF NUMS=");

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("ELEMENTS OF NUMS=");
    for (int i = 0; i < n; i++)
        printf("%d", nums[i]);
    
    printf("\n");

    int target;
    printf("ENTER THE TARGET=");
    scanf("%d", &target);

    sumequaltarget(nums,n,target);
}
int sumequaltarget(int nums[],int n,int target)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i+1; j < n; j++)
        {
            sum = nums[i] + nums[j];
            if (sum == target)
            {
                printf("%d %d", i, j);
                return 1;
            }
        }
    }
    printf("-1,-1");
    return 0;
}
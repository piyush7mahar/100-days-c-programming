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

    int target;
    printf("ENTER THE TARGET=");
    scanf("%d",&target);

    int first=-1;
    int last=-1;
    int fin=-1;
    int lin=-1;
    for(i=0;i<n;i++)
    {
        if (nums[i]==target)
        {
            if(first==-1)
            {
                first=nums[i];
                fin=i;
            }

            last=nums[i];
            lin=i;

        }
    }

    printf("FIRST OCCURANCE OF TARGET=%d\n",first);
    printf("INDEX FIRST OCCURANCE OF TARGET=%d\n",fin);
    printf("LAST OCCURANCE OF TARGET=%d\n",last);
    printf("INDEX LAST OCCURANCE OF TARGET=%d\n",lin);

    return 0;
}
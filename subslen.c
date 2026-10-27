#include <stdio.h>
#include <string.h>
int longestsubstring(char str[]);
int main()
{
    char str[100];
    printf("ENTER THE STRING=");
    scanf("%s", str);

    longestsubstring(str);
    return 0;
}

int longestsubstring(char str[])
{
    int n=strlen(str);
    int max=0;
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=i;j<n;j++)
        {
            int repeat=0;
            for(int k=i;k<j;k++)
            {
                if(str[k]==str[j])
                {
                    repeat=1;
                    break;
                }
            }
            if(repeat==1)
                break;
            count++;

            if(count>max)
                max=count;
        }
    }
    printf("LENGTH OF LONGEST SUBSTRING=%d", max);
}
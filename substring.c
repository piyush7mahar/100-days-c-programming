#include<stdio.h>
#include<string.h>
int main()
{
    char str[]="abcd";
    int n;
    n=strlen(str);

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
                printf("%c",str[k]);
                printf("\n");
        }
    }
    return  0;
}
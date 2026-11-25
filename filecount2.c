#include<stdio.h>
int main()
{
    FILE *f;
    char ch;
    int sum=0;

    f=fopen("number.txt","r");

    if (f==NULL)
    {
        printf("FILE NOT FOUND");
        return 0;
    }

    while((ch=fgetc(f))!=EOF)
    {
        if(ch>='0' && ch<='9')
            sum=sum+(ch-'0');
    }

    printf("SUM OF THE INTEGERS IN FILE=%d",sum);
    fclose(f);

    return 0;
}
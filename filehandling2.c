#include<stdio.h>
int main()
{
    FILE *f;
    f=fopen("tetx.txt","r");

    if (f==NULL)
        printf("FILE DOESNT EXIST");

    char line[100];
    while ((fgets(line,100,f))!=NULL)
    {
        printf("%s",line);
    }

    fclose(f);
    return 0;
    
}

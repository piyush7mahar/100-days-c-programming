#include <stdio.h>
int main()
{
    FILE *f;
    char filename[100];
    char ch;

    printf("ENTER FILE NAME:");
    scanf("%s",filename);

    f=fopen(filename,"r");

    if (f==NULL)
    {
        printf("FILE DOES NOT EXIST");
        return 0;
    }

    printf("FILE OPENED SUCCESSFULLY\n");
    printf("CONTENT OF FILE:\n");

    while ((ch=fgetc(f))!=EOF)
        printf("%c",ch);

    fclose(f);

    return 0;
}
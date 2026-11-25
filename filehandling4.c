#include<stdio.h>
int main()
{
    FILE *f,*o;
    char ch;

    f=fopen("input.txt","r");
    o=fopen("output.txt","w");

    if (f==NULL)
    {
        printf("FILE NOT FOUND.");
        return 0;
    }
    
    while((ch=fgetc(f))!=EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 32;
        }
        fputc(ch,o);
    }

    fclose(f);
    fclose(o);

    printf("OUTPUT FILE DATA=\n");
    
    o=fopen("output.txt","r");

    while((ch=fgetc(o))!=EOF)
    {
        printf("%c",ch);
    }

    fclose(o);

    return 0 ;
}

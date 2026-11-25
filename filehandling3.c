#include<stdio.h>
int main()
{
    FILE *f;    

    f=fopen("data.txt","r");
    if (f==NULL)
    {
        printf("FILE DOESNT EXIST");
        return 1;
    }
    int ch;
    int character=0,word=0,line=0;
    int inword=0;
    while ((ch=fgetc(f))!=EOF)
    {
        character++;
        if (ch=='\n')
            line++;
        if (ch == ' ' || ch=='\n' || ch=='\t')
            inword=0;
        else if(inword==0)
        {
            word++;
            inword=1;
        } 
    }

    printf("CHARACTERS=%d\n",character);
    printf("WORDS=%d\n",word);
    printf("LINES=%d\n",line);

    fclose(f);

    return 0;
    
}
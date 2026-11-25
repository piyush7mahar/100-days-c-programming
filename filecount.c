#include<stdio.h>
int main()
{
    FILE *f;
    char ch;
    int vowel=0;
    int consonant=0;

    f=fopen("input.txt","r");

    if (f==NULL)
    {
        printf("FILE NOT FOUND");
        return 0;
    }

    while((ch=fgetc(f))!=EOF)
    {
        if(ch>'A' && ch<'Z')
            ch=ch-32;
        if(ch>'a' && ch<'z')
        {
            if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                vowel++;
            else
                consonant++;
        }
    }

    printf("VOWELS = %d\n", vowel);
    printf("CONSONANTS = %d\n", consonant);

    fclose(f);

    return 0;
}
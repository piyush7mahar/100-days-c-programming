#include<stdio.h>
int main()
{
    char c;
    printf("ENTER ANY CHARACTER:");
    scanf("%c",&c);

    if (c>='A' && c<='Z')
    {
        if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        {
            printf("UPPERCASE AND VOWEl");
        }else 
            printf("UPPERCASE AND CONSONANT");
    }else if (c>='a' && c<='z')
    {
        if (c=='a' || c=='e' ||c=='u' || c=='i' || c=='o')
        {
            printf("LOWERCASE AND VOWEL");
        }else 
            printf("LOWERCASE AND CONSONANT");
    }else 
        printf("INVALID VLAUE");
    
    return 0;
}
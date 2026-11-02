#include <stdio.h>
#include <string.h>
int main()
{
    char s[100], t[100];
    printf("ENTER FIRST STRING=");
    scanf("%s",s);

    printf("ENTER SECOND STRING=");
    scanf("%s",t);

    if(strlen(s)!=strlen(t))
    {
        printf("Not Anagram");
        return 0;
    }

    int count[26]={0};
    for(int i = 0; s[i] != '\0'; i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for(int i = 0; i < 26; i++)
    {
        if(count[i] != 0)
        {
            printf("Not Anagram");
            return 0;
        }
    }
    printf("Anagram");
    return 0;
}
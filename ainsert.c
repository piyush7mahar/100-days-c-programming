#include <stdio.h>

int main()
{
    int a[6] = {15,21,33,42,60};
    int num = 35;
    int i, pos;

    for(i = 0; i < 5; i++)
    {
        if(num < a[i])
        {
            pos = i;
            break;
        }
    }

    for(i = 5; i > pos; i--)
        a[i] = a[i - 1];

    a[pos]=num;

    for(i=0;i<6;i++)
        printf("%d ",a[i]);

    return 0;
}

//PROGRAM TO INPUT AN INTEGER AND PRINT IF IT POSITIVE,NEGATIVE OR ZERO :::::

#include<stdio.h>
int main()
{
    int num;
    printf("ENTER ANY NUMBER:");

    if (scanf("%d",&num)==1)
    {
        if (num>0)
            printf("IT IS POSITIVE");
        else if (num<0)
            printf("IT IS NEGATIVE");
        else
            printf("IT IS ZERO");
    }else
         printf("NOT VALID");

    return 0;
}
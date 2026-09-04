//PROGRAM TO FIND PROFIT AND LOSS PERCENTAGE:
#include<stdio.h>
int main()
{
    float cp;
    printf("ENTER THE COST PRICE=");
    scanf("%f",&cp);

    float sp;
    printf("ENTER THE SELLING PRICE=");
    scanf("%f",&sp);

    float pp;
    pp= ((sp-cp)/cp)*100;

    float lp;
    lp= ((cp-sp)/cp)*100;

    if (sp>cp)
    {
        printf("PROFIT PERCENTAGE=%f",pp);
    }else if (cp>sp)
    {
        printf("LOSS PERCENTAGE=%f",lp);
    }else
        printf("INVALID VALUE");

        
    return 0;
}

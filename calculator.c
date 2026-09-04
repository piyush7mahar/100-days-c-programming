#include<stdio.h>
int main()
{
    int n1;
    printf("ENTER NUMBER 1=");
    scanf("%d",&n1);

    int n2;
    printf("ENTER NUMBER 2=");
    scanf("%d",&n2);
    
    int sum;
    sum= n1+n2;

    int diff;
    diff=n1-n2;

    int div;
    div=n1/n2;

    int multiply;
    multiply=n1*n2;

    char s;
    printf("ENTER ANY (+,-,/,*)=");
    scanf(" %c",&s);

    switch (s) {
        case '+' :
        printf("sum=%d",sum);
        break;
        case '-' :

        printf("diff=%d",diff);
        break;
        case '/' :
            
        printf("div=%d",div);
        break;
        case '*' :
            
        printf("multiply=%d",multiply);
        break;
        
        
    }
    return 0;

    
}
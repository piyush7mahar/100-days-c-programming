#include<stdio.h>
 int main() {
    int n;
    printf("ENTER THE NUMBER=");
    scanf("%d",&n);
    
    int sum;
    sum =(n*(n+1))/2;
    printf("SUM OF n NATURAL NUMBERS= %d",sum);

    return 0;
 }
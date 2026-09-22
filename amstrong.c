//Write a program to check if a number is an Armstrong number.

#include <stdio.h>
int main()
{
    int n;
    printf("ENTER ANY NUMBER=");
    scanf("%d",&n);

    int original = n;
    int digit;
    int result = 0;

    while (n != 0) {
        digit = n % 10;
        result += digit * digit * digit;
        n /= 10;
    }

    if (original == result)
        printf("it is amstrong=%d", result);
    else
        printf("not an amstrong");

    return 0; 
        
        

}
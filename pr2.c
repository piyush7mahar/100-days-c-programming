//Write a program to find the sum of the series: 2/3 + 4/7 + 6/11 + 8/15 + ... up to n terms.

#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("%d/%d", 2 * i, 4 * i - 1);

        if (i < n)
            printf(" + ");
    }

    return 0;
}
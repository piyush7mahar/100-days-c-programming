//	Create an enum for months and print how many days each month has.

#include <stdio.h>

enum month
{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

int main()
{
    enum month m;

    for (m = JANUARY; m <= DECEMBER; m++)
    {
        switch (m)
        {
            case JANUARY:
                printf("JANUARY = 31 DAYS\n");
                break;

            case FEBRUARY:
                printf("FEBRUARY = 28 DAYS\n");
                break;

            case MARCH:
                printf("MARCH = 31 DAYS\n");
                break;

            case APRIL:
                printf("APRIL = 30 DAYS\n");
                break;

            case MAY:
                printf("MAY = 31 DAYS\n");
                break;

            case JUNE:
                printf("JUNE = 30 DAYS\n");
                break;

            case JULY:
                printf("JULY = 31 DAYS\n");
                break;

            case AUGUST:
                printf("AUGUST = 31 DAYS\n");
                break;

            case SEPTEMBER:
                printf("SEPTEMBER = 30 DAYS\n");
                break;

            case OCTOBER:
                printf("OCTOBER = 31 DAYS\n");
                break;

            case NOVEMBER:
                printf("NOVEMBER = 30 DAYS\n");
                break;

            case DECEMBER:
                printf("DECEMBER = 31 DAYS\n");
                break;
        }
    }

    return 0;
}
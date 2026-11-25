//	Create an enumeration for days (SUNDAY to SATURDAY) and print each day with its integer value.

#include<stdio.h>
int main()
{
    enum days
    {
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
    };

    printf("Sunday=%d\n",Sunday);
    printf("Monday=%d\n",Monday);
    printf("Tuesday=%d\n",Tuesday);
    printf("Wednesday=%d\n",Wednesday);
    printf("Thursday=%d\n",Thursday);
    printf("Frinday=%d\n",Friday);
    printf("Saturday=%d\n",Saturday);

    return 0;

}
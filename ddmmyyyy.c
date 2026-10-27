//	Change the date format from dd/04/yyyy to dd-Apr-yyyy.

#include <stdio.h>
int main()
{
    int day, month, year;
    printf("ENTER YOUR DAY OF BIRTH(dd)=");
    scanf("%d/", &day);

    printf("ENTER YOUR MONTH OF BIRTH(mm)=");
    scanf("%d/", &month);

    printf("ENTER YOUR YEAR OF BIRTH(yyyy)=");
    scanf("%d/", &year);

    if (month == 4 || month == 04)
        printf("YOUR DATE OF BIRTH = %d-apr-%d", day, year);
    return 0;
}
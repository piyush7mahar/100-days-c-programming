#include <stdio.h>
int main()
{
    FILE *f;
    char name[50];
    int rollno;
    float marks;
    int n;

    f=fopen("student.txt","w");

    if(f==NULL)
    {
        printf("FILE CANNOT BE OPENED");
        return 0;
    }

    printf("ENTER NUMBER OF STUDENTS = ");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
        printf("ENTER NAME=");
        scanf("%49s", name);

        printf("ENTER ROLL NUMBER=");
        scanf("%d", &rollno);

        printf("ENTER MARKS=");
        scanf("%f", &marks);

        fprintf(f, "%s %d %.2f\n", name, rollno, marks);
    }

    fclose(f);

    f = fopen("student.txt", "r");

    if (f==NULL)
    {
        printf("FILE NOT FOUND");
        return 0;
    }

    printf("\nSTUDENT RECORDS:\n");

    while (fscanf(f, "%49s %d %f", name, &rollno, &marks) == 3)
    {
        printf("NAME: %s\n", name);
        printf("ROLL: %d\n", rollno);
        printf("MARKS: %.2f\n", marks);
        printf("\n");
    }

    fclose(f);

    return 0;
}
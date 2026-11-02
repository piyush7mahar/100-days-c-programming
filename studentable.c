#include<stdio.h>
struct student
{
    char name[100];
    int rollno;
    float marks;
    
};

int main()
{
    int n;
    printf("ENTER NUMBER OF RECORDS=");
    scanf("%d",&n);

    struct student s[n];

    for(int i=0;i<n;i++)
    {
        printf("ENTER NAME=");
        scanf("%s",s[i].name);
        printf("ENTER ROLL NO=");
        scanf("%d",&s[i].rollno);
        printf("ENTER MARKS=");
        scanf("%f",&s[i].marks);

        printf("\n");
    }

    printf("-----------STUDENT TABLE-----------\n");
    printf("%-15s %-10s %-10s\n", "NAME", "ROLL NO", "MARKS");
    printf("-----------------------------------\n");
    for (int i=0;i<n;i++)
    {
        printf("%-15s %-10d %-10.2f\n",s[i].name,s[i].rollno,s[i].marks); 
    }
    printf("-----------------------------------\n");

    int i=0;
    float max=0;
    int topper=0;
    for(i=0;i<n;i++)
    {
        if(max<s[i].marks)
        {
            max=s[i].marks;
            topper=i;
        }
    }
    printf("MAXIMUM MARK=%.2f\n",max);
    printf("TOPPER=%s",s[topper].name);
    
    return 0;
}
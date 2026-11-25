#include<stdio.h>
int main()
{
    FILE *f;
    f=fopen("data.txt","w");

    char name[100];
    printf("ENTER THE NAME=");
    scanf("%s",name);

    int age;
    printf("ENTER THE AGE=");
    scanf("%d",&age);

    fprintf(f, "NAME = %s\n", name);
    fprintf(f, "AGE = %d\n", age);

    fclose(f);
    
    printf("DATA IS SUCCESSFULLY SAVED");

    return 0;

}
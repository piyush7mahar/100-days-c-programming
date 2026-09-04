/*circumference of circle */
#include<stdio.h>
int main(){
    float r;
    printf("enter r ");
    scanf("%f",&r);
    
    float c = (2*3.14*r);
    printf("circumference of circle=%f\n",c );

    float a = (3.14*r*r);
    printf("area of circle=%f\n",a);

    return 0;

}
//	Define an enum for traffic lights (RED, YELLOW, GREEN) and print 'Stop', 'Wait', or 'Go' based on its value.

#include<stdio.h>
int main()
{
    enum traffic
    {
        RED,
        YELLOW,
        GREEN,
    };

    enum traffic light;

    printf("ENTER TRAFFIC LIGHT(0,1,2)=");
    scanf("%d",&light);
    switch(light)
    {
        case RED:
        printf("STOP");
       
        case YELLOW:
        printf("WAIT");
       
        case GREEN:
        printf("GO");
    }

    return 0;
}
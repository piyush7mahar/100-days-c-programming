#include<stdio.h>
 int main() {
    
    int t_seconds;
    printf("ENTER TIME IN SECONDS:");
    scanf("%d",&t_seconds);

    int hours;
    hours=t_seconds/3600;
    printf("hours:%d",hours);

    int minutes;
    minutes=(t_seconds%3600)/60;
    printf(",minutes:%d",minutes);

    int seconds;
    seconds=t_seconds%60;
    printf(",seconds:%d",seconds);

    return 0;
 }
#include<stdio.h>
int main()
{
    float speed,limited_speed;
    float exceed;
    scanf("%f %f",&speed,&limited_speed);
    if(speed<limited_speed)
    {
        printf("OK");
        return 0;
    }
    exceed = (speed-limited_speed)/limited_speed;
    if(exceed<0.1)
        printf("OK");
    else if(exceed>=0.1&&exceed<0.5)
        printf("Exceed %.0f\%%. Ticket 200",exceed*100);
    else
        printf("Exceed %.0f\%%. License Revoked",exceed*100);
    return 0;

}

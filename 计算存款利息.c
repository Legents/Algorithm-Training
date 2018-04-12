#include<stdio.h>
#include<math.h>
int main()
{
    int money,year;
    float interest,rate;
    do{
        scanf("%d %d %f",&money,&year,&rate);
    }while(money<=0||year<=0||rate<=0);
    interest = money*pow((1+rate),year)-money;
    printf("intreast = %.2f",interest);
    return 0;

}

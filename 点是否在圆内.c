#include<stdio.h>
int main()
{
    int x,y;
    float distance;
    scanf("%d %d",&x,&y);
    distance=sqrt((x*x+y*y));
    if(distance>=10)
        printf("0");
    else
        printf("1");
    return 0;
}

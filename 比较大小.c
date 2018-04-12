#include<stdio.h>
int main()
{
    int a[3],i,j,t;
    for(i=0;i<3;i++)
        scanf("%d",&a[i]);
    if(a[0]>a[1])
        {
            t=a[0];
            a[0]=a[1];
            a[1]=t;}
    if(a[1]>a[2])
        {
            t=a[1];
            a[1]=a[2];
            a[2]=t;}
    if(a[0]>a[1])
        {
            t=a[0];
            a[0]=a[1];
            a[1]=t;
            }
    printf("%d->%d->%d",a[0],a[1],a[2]);
    return 0;
}

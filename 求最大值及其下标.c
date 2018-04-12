#include<stdio.h>
int main()
{
    int n,max,loca,i;
    do{
        scanf("%d",&n);
    }while(n<=1||n>10);
    int num[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    max=num[0];
    for(i=0;i<n;i++)
    {
        if(max<num[i])
        {
            max=num[i];
            loca=i;
        }
    }
    printf("%d %d ",max,loca);
    return 0;
}

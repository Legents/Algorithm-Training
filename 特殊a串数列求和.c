#include<stdio.h>
int main()
{
    int a,n,i,sum=0,num=0;
    do{
        scanf("%d %d",&a,&n);
    }while(a<=0||a>9||n<=0||n>9);
    for(i=0;i<n;i++)
    {
        num=(num*10+a);
        sum+=num;
    }

    printf("s = %d",sum);
    return 0;
}

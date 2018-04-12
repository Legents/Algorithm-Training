#include<stdio.h>
int main()
{
    int N,n=0,sum=0;
    do{
        scanf("%d",&N);
    }while(N<=0||N>10000000000);
    while(N)
    {
        sum+=N%10;
        N/=10;
        n++;
    }
    printf("%d %d",n,sum);
    return 0;
}

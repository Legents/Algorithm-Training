#include<stdio.h>
int main()
{
    int sum=1,N,i;
    do{
        scanf("%d",&N);
    }while(N<=1||N>10);
    for(i=1;i<N;i++)
    {
        sum=(sum+1)*2;
    }
    printf("%d",sum);
    return 0;
}

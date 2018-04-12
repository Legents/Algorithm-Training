#include<stdio.h>
int main()
{
    int i,j,N;
    do{
        scanf("%d",&N);
    }while(N<1||N>9);
    for(i=1;i<N+1;i++)
    {
        for(j=1;j<=i;j++)
        {
        printf("%d*%d=%-4d",i,j,i*j);
        }
    printf("\n");
    }
    return 0;
}

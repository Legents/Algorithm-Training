#include<stdio.h>
int main()
{
    int i,j,k,cash,count=0;
    do{
       scanf("%d",&cash);
    }while(cash<=8||cash>=100);

    for(i=cash-2-5;i>0;i--)
        for(j=(cash-1-5)/2;j>0;j--)
            for((k=cash-1-2)/5;k>0;k--)
    {
        if((i*1+j*2+k*5)==cash)
            {
                printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",k,j,i,i+j+k);
                count++;
            }
    }
    printf("count = %d",count);
    return 0;
}

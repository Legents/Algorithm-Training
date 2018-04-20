#include<stdio.h>
int main()
{
    int M,K,N,i,j,temp,count=0;
    do{
        scanf("%d%d%d",&M,&K,&N);
    }while(M>1000||K>20||N>M);
    int a[M][2];
    int b[M];
    for(i=0;i<M;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
        b[i]=a[i][1];
    }
    for(i=0;i<M;i++)
        for(j=i+1;j<M;j++)
        if(b[i]<b[j])
        {
            temp=b[i];
            b[i]=b[j];
            b[j]=temp;
        }
    for(i=0;i<M;i++)
    {
        if(a[i][0]==K)
        {
            if(a[i][1]>=b[N-1])
            {
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}

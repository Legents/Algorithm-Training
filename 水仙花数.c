#include<stdio.h>
#include<math.h>
int main()
{
    int i,m,N,res;
    do{
        scanf("%d",&N);
    }while(N<3||N>7);
    for(i=pow(10,N-1);i<pow(10,N)-1;i++)
    {
        res=0;
        m=i;
        while(m){
        res+=pow(m%10,N);
        m/=10;
        }
        if(res==i)
            printf("%d\n",i);
    }
    return 0;


}

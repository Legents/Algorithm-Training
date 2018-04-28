#include<stdio.h>
int main()
{
    long long n,i,res=1,sum=0;
    do{
    scanf("%lld",&n);
    }while(n<1||n>1000000000);
    for(i=1;i<=n;i++){
        res*=i;
        res%=1000000;
        sum+=res;
        sum%=1000000;
    }
    printf("%lld",sum);
    return 0;
}


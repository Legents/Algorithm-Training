#include<stdio.h>
int main()
{
    long long i,a,b,m,res=1;
    do{
        scanf("%lld%lld%lld",&a,&b,&m);
    }while(a>=1000000000||b>=1000000000000000000||m<=1||m>=1000000000);
    for(i=0;i<b;i++){
        res=res*a%m;
    }
    printf("%lld",res);
    return 0;
}

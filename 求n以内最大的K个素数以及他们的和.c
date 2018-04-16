#include<stdio.h>
#include<math.h>
int IsPrime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return 0;
    return 1;
}
int main()
{
    int n,k,sum=0;
    do{
        scanf("%d %d",&n,&k);
    }while(n<10||n>10000||k<1||k>10);
	while(k>=1&&n>=2){
		if(IsPrime(n)){
			sum+=n;
			printf("%d",n);
			k--;
			if(k>=1&&n>2)
				printf("+");
		}
		n--;
	}
	printf("=%d",sum);
    return 0;
}

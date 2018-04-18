#include<stdio.h>
#include<math.h>
int IsPrime(int n){
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
int main(){
	int M,N,count=0,i,sum=0;
	do{
		scanf("%d%d",&M,&N);
	}while(M<1||M>500||M>N||N<1||N>500);
	for(i=M;i<=N;i++){
		if(IsPrime(i)){
			count++;
			sum+=i;
		}
	}
	printf("%d %d",count,sum);
	return 0;
} 

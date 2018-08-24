#include<stdio.h>
int fib(int n){
	if(n==1) return 0;
	else if(n==2) return 1;
	else return fib(n-1)+fib(n-2);
} 
int main(){
	int n,m;
	printf("输入项数：");
	scanf("%d",&n);
	m=fib(n);
	printf("第%d项是%d\n",n,m);
	int i;
	m=0;
	for(i=1;i<=n;i++){
		m=fib(i)+m;
		printf("前%d项的和为%d\n",i,m);
	}
	return 0;
}

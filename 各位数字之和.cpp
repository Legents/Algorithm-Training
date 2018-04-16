#include<stdio.h>
int main(){
	int sum=0,num;
	do{
		scanf("%d",&num);
	}while(num<=0);
	while(num){
		sum+=num%10;
		num/=10;
	}
	printf("%d",sum);
	return 0;
} 

#include<stdio.h>
#include<limits.h>
int main(){
	int min,n,i,num;
	do{
		scanf("%d",&n);
	}while(n<=0);
	min=INT_MIN;
	for(i=0;i<n;i++){
		scanf("%d",&num);
		if(num<min)
			min=num;
	}
	printf("min = %d",min);
	return 0;
} 

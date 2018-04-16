#include<stdio.h>
#include<stdlib.h>
int main(){
	int num1,num2,res,flag=0;
	do{
		num1=(int)rand()%100;
	}while(num1<0||num1>100);
	do{
		scanf("%d",&num2);
	}while(num2<3);
	printf("%d %d",num1,num2);
	while(num2>0){
		scanf("%d",&res);
		if(res>num1)
			printf("Too big");
		else if(res<num1)
			printf("Too small");
		else if(res==num1){
			flag=1;
			printf("Good Guess!");
			return 0;
		}
	}
	if(flag==0&&num2==0){
		printf("Game Over");
		
	}
} 

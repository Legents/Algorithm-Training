#include<stdio.h> 
int fun(int num){
	if(num==7)
		return 1;
	else if(num==4)
		return 1;
	else 
		return fun(num/4)+fun(num/7); 
} 
int main(){
	int num;
	scanf("%d",&num);
	printf("%d",fun(num));
	return 0;
}

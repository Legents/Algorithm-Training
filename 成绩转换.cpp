#include<stdio.h>
int main(){
	int score;
	do{
		scanf("%d",&score);
	}while(score<0||score>100);
	switch(score/10){
		case 10:
		case 9:printf("A");break;
		case 8:printf("B");break;
		case 7:printf("C");break;
		case 6:printf("D");break;
		default:printf("E");break;
	}
	return 0;
} 

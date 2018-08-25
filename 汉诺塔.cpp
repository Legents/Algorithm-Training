#include<stdio.h>
int count=0;
void move(int n,char x,char y){
	printf("把%d号从%c移动到%c\n",n,x,y);
	count++;
} 
void Hannoi(int n,char a,char b,char c){
	if(n==1)
		move(1,a,c);
	else{
		Hannoi(n-1,a,c,b);
		move(n,a,c);
		Hannoi(n-1,b,a,c);
	}
}
int main(){
	int n;
	printf("输入盘子的个数；"); 
	scanf("%d",&n);
	Hannoi(n,'A','B','C');
	printf("一共移动了%d次盘子！\n",count);
	return 0;
}

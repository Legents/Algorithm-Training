#include<stdio.h>
void move(int n,char x,char y){
	printf("��%d�Ŵ�%c�ƶ���%c\n",n,x,y);
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
	printf("�������ӵĸ�����"); 
	scanf("%d",&n);
	Hannoi(n,'A','B','C');
	return 0;
}

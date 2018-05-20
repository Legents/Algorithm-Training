#include<stdio.h>
int main(){
	int n,k;
	scanf("%d",&n);
	while(n--){
		int y,nu;
		scanf("%d%d",&y,&nu);
		int num=0;
		for(k=y;;k++){
			if(num==nu)
				break;
			if(k%4==0&&k%100!=0||k%400==0)
				num++;
		}
		printf("%d\n",k-1);
	}
	return 0;
}

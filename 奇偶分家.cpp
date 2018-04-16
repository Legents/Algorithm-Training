#include<stdio.h>
int main()
{
	int i,m=0,n=0,num,p;
	do{
		scanf("%d",&num);
	}while(num>1000||num<0);
	for(i=0;i<num;i++){
		scanf("%d",&p);
		if(p%2==0)
			m++;
		else
			n++;
	}
	printf("%d %d",n,m);
	return 0;
 } 

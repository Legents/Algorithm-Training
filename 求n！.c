#include<stdio.h>
int main()
{
	int n,i,res=1;
	do{
		scanf("%d",&n);
	}while(n<0||n>=10);
	for(i=1;i<=n;i++)
		res*=i;
	printf("%d",res);
	return 0;
 } 

#include<stdio.h>
int main()
{
	int v1,v2;
	int sum=0;
	char ch;
	scanf("%d",&v1);
	while((ch=getchar())!='=')
	{
		scanf("%d",&v2);
		if(ch=='/'&&v2==0)
		{
			printf("ERROR");
			return 0;
		}
		switch(ch)
		{
			case '+':sum=v1+v2;break;
			case '-':sum=v1-v2;break;
			case '*':sum=v1*v2;break;
			case '/':sum=v1/v2;break;
			default:printf("ERROR");return 0;
		}
		v1=sum;
	}
	printf("%d",v1);
	return 0;
 } 

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,d,u;
	int t;
	int s=00;
	while(scanf("%d%d%d",&n,&d,&u)&&n||d||u){
		t=0;
		s=0;
		while(1){
			s+=d;
			t++;
			if(s>=n)
				break;
			s-=u;
			t++;
		}
		printf("%d\n",t);
	}
	return 0;
}

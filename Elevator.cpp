#include<stdio.h>
int main(){
	int a[100];
	int n,i;
	while(scanf("%d",&n)&&n){
		int sum=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sum+=5*n;
		sum+=a[0]*6;
		for(i=0;i<n-1;i++){
			if(a[i]<a[i+1])
				sum+=(a[i+1]-a[i])*6;
			else if(a[i]>a[i+1])
				sum+=(a[i]-a[i+1])*4;
		}
		printf("%d\n",sum);
	}
	return 0;
}

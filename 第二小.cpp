#include<stdio.h>
int main(){
	int m=101,n=101;
	int a,i,num;
	while(scanf("%d",&num)){
		if(num>=2&&num<=10){
			for(i=0;i<num;i++){
			do{
				scanf("%d",&a);
			}while(a>=100);
			if(a<m||a<n){
				m>n?n=a:m=a;
			}
		}
		printf("%d",m<n?n:m);
		}
		
	}
	return 0;
} 

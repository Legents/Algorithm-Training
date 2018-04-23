#include<stdio.h>
int main(){
	int h,m,s,n;
	do{
		scanf("%d:%d:%d",&h,&m,&s);
	}while(h<0||h>=24||m<0||m>=60||s<0||s>=60);
	do{
		scanf("%d",&n);
	}while(n<0||n>=60);
	if(s+n>=60){
		if(m+1>=60){
			if(h+1>=24){
				h=h+1-24;
				m=m+1-60;
				s=s+n-60;
			}
			else
				h+=1;
		}
		else
			m+=1;
	}
	else
		s+=n;
	printf("%02d:%02d:%02d",h,m,s);
	return 0;
} 

#include<stdio.h>
#include<string.h>
int main(){
	int room[205];
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(room,0,sizeof(room));
		int i=0;
		for(i=0;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x>y){
				int t=x;
				x=y;
				y=t;
			}
			x=(x-1)/2;
			y=(y-1)/2;
			int j;
			for(j=x;j<=y;j++){
				room[j]++;
			}
		}
		int time=-1;
		for(i=0;i<205;i++)
			if(time<room[i])
				time=room[i];
				
		time*=10;
		printf("%d\n",time);
	}
	return 0;
} 

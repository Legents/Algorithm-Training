#include<stdio.h>
int main(){
	char c[10000],i=0,j,num=0;
	for(i=0;i<10000;i++){
		scanf("%c",&c[i]);
		if(c[i]=='.')
			break;
	} 
	for(j=0;j<=i;j++){
		if(c[j]!=' '&&c[j]!='.')
			num++;
		else {
			printf("%d",num);
			num=0;
			if(c[j]!='.')
				printf(" ");
		}
	}
	return 0;
}

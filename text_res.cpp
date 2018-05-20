#include<stdio.h>
#include<string.h>
int main(){
	int n,i,j,k,len,a1,b1;
	char a[1000],b[1000];
	scanf("%d",&n);
	getchar();
	while(n--){
		gets(a);
		len=strlen(a);
		for(b1=0,i=0;i<len;i++){
			if(a[i]!=' '){
				b[b1]=a[i];
				b1++;
			}
			else{
				for(j=b1-1;j>=0;j--)
					printf("%c",b[j]);
				printf(" ");
				b1=0;
			}
		}
		for(j=b1-1;j>=0;j--)
			printf("%c",b[j]);
		printf("\n");
	}
	return 0;
}

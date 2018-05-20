#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n,i,j;
	__int64 num;
	char inputNum[1005];
	char *nums;
	char *system;
	while(~scanf("%d",&n)){
		num=0;
		while(n--){
			scanf("%s",inputNum);
			nums=strtok(inputNum,"(");
			system=strtok(NULL,")");
			num+=strtol(inputNum,NULL,atoi(system));
			}
		printf("%I64d\n",num);
	}
		
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char str[1000];
	int i,len;
	while(gets(str)){
		if(!strcmp(str,"#"))
		exit(0);
	len = strlen(str);
	for(i=0;i<len;i++){
		switch(str[i]){
			case ' ':printf("%%20");break;
			case '!':printf("%%21");break;
			case '$':printf("%%24");break;
			case '%':printf("%%25");break;
			case '(':printf("%%28");break;
			case ')':printf("%%29");break;
			case '*':printf("%%2a");break;
			default:printf("%c",str[i]);
		}
	}
	printf("\n");
	}
	
	return 0;
}

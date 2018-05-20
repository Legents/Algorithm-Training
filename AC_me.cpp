#include<stdio.h>
#include<string.h>
int main(){
	char a[100001];
	int c[26],s,i;
	while(gets(a)!=NULL)
	{
		memset(c,0,sizeof(c));
		for(i=0;a[i]!='\0';i++)
		{
			s=a[i]-'a';
			c[s]++;
		}
		for(i=0;i<26;i++)
			printf("%c:%d\n",'a'+i,c[i]);
		printf("\n");
	}
	return 0;
}

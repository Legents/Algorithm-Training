#include<stdio.h>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
int main()  
{  
    char a[8];  
    gets(a);  
    int len=strlen(a);  
    sort(a,a+len);//Ҫ���ź�����Ϊ���ǰ����ֵ�˳���Զ��ŵ�  
    puts(a);  
    while(next_permutation(a,a+strlen(a)))//����ȫ���к���  
    puts(a);  
    return 0;  
} 

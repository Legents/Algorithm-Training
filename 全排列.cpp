#include<stdio.h>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
int main()  
{  
    char a[8];  
    gets(a);  
    int len=strlen(a);  
    sort(a,a+len);//要先排好序，因为他是按照字典顺序自动排的  
    puts(a);  
    while(next_permutation(a,a+strlen(a)))//调用全排列函数  
    puts(a);  
    return 0;  
} 

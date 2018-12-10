#include<stdio.h>
#include<limits.h>
 
int reverse(int x) {
	if(x>INT_MAX/10||x<(INT_MIN-1)/10)
		x=0; 
    int temp = x>=0?x:-x;
    int res=0;
    while(temp){
        res=res*10+(temp%10);
        temp/=10;
    }
    if(x<0)
        res=-res;
    return res;
}
int main(){
	int x=-2147483648;
	printf("%d,%d",x,reverse(x));
	return 0;
} 

#include <iostream>

using namespace std;
int fun(int x,int y)
{
	if(x==1) return y+1;
	else if(y==1) return x+1;
	else if(x==0 || y==0) return 0;
	else return fun(x-1,y)+fun(x,y-1);
}
int main()
{
	int m,n;
	while(cin>>m>>n) cout<<fun(m,n)<<endl;
	return 0;
} 


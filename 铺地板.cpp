#include <iostream>

using namespace std;
int fun(int x)
{
	if(x<1) return 0;
	else if(x==1) return 1;
	else if(x==2) return 2; 
	else return fun(x-1)+fun(x-2);//µÝÍÆ 
}
int main()
{
	int m;
	while(cin>>m) cout<<fun(m)<<endl;
	return 0;
} 

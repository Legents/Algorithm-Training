#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

int main()
{
	string a,b;
	int sum[102]={0};//������Ŵ����ݵĺ� 
	getline(cin,a);
	getline(cin,b);
    int	Len_a=a.size(),Len_b=b.size();
    int count=min(Len_a,Len_b);
    int t1,t2;
    int L1=Len_a,L2=Len_b,L3=101;
    //�ȴ����ַ���a��b��ͬ���ȵ��ַ����������ַ������λ��ʼ��ǰ���� 
    for(int i=0;i<count;i++)
    {
    	t1=a[L1-1]-'0'+b[L2-1]-'0';
    	t2=sum[L3]+t1;
    	sum[L3]=t2%10;
    	sum[L3-1]=t2/10;
    	L1--;
    	L2--;
    	L3--;
    }
    //�����Ƚϴ��ַ�������Ĳ��� 
    if(Len_a>Len_b)
    {
    	for(int i=L1-1;i>=0;i--)
		{
			t1=a[i]-'0';
			t2=sum[L3]+t1;
			sum[L3]=t2%10;
    	    sum[L3-1]=t2/10;
			L3--;			
		} 
    }
    
    if(Len_a<Len_b)
    {
    	for(int i=L2-1;i>=0;i--)
		{
			t1=b[i]-'0';
			t2=sum[L3]+t1;
			sum[L3]=t2%10;
    	    sum[L3-1]=t2/10;
			L3--;			
		} 
    }
    //�ҵ����ֺ͵Ŀ�ʼ���� 
    int num;
    for(int i=0;i<102;i++)
    {
    	if(sum[i]!=0) 
		{
			num=i;
			break;
		}
    }
    
    for(int i=num;i<102;i++) cout<<sum[i];   
	return 0;
}

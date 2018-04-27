#include<iostream>
#include<cmath>
using namespace std;
class Time{
    private:
        int h,m;
    public:
        Time(int H,int M){
            this->h=H;
            this->m=M;

        }
        int operator-(Time a);

};
int Time::operator -(Time a){
        int sum1=this->h*60+this->m;
        int sum2=a.h*60+a.m;
        return fabs(sum1-sum2);
}
int main(){
    int a,b,c,d;
    do
    {
        do{
        cin>>a>>b>>c>>d;
    }while(a<0||a>23||b<0||b>59||c<0||c>23||d<0||d>59);
    Time a1(a,b),b1(c,d);
    if(a!=0||b!=0||c!=0||d!=0)
        cout<<a1-b1<<endl;
    }while(a!=0||b!=0||c!=0||d!=0);
    return 0;
}


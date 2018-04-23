#include<stdio.h>
#include<math.h>
int IsPrime(int n){
  int i;
  for(i=2;i<=sqrt(n);i++)
    if(n%i==0)
       return 0;
  return 1;
}
int main(){
  int n,i,flag=0,num;
  do{
    scanf("%d",&n);
  }while(n<0||n>=20);
  for(i=2;i<n;i++){
  	num=pow(2,i)-1;
    if(IsPrime(num)){
      printf("%d\n",num);
      flag=1;
    }
      
  }
  if(flag==0)
    printf("None");
  return 0;
}

#include<stdio.h>
int main(){
  int i,Sum=0,n;
  float ave;
  for(i=0;i<4;i++){
    scanf("%d",&n);
    Sum+=n;
  }
  ave=Sum/4.0;
  printf("Sum = %d; Average = %.1f",Sum,ave);
  return 0;
}

#include<stdio.h>
#include<math.h>
int prime(int n){
    int i;
    for(i=2;i<=int(sqrt(n));i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main(){
    int m,n,i,j=0,count=0;
        scanf("%d%d",&m,&n);
    for(i=1;;i++){
        if(prime(i)){
            count++;
            if(count>m&&count<=n+1)
            {printf("%d",i);
            j++;
            if(j<10)
                printf(" ");
            if(j==10){
                printf("\n");
                j=0;
            }}
        }
        if(count>=10000||count==n+1)
            break;
    }
    return 0;
}

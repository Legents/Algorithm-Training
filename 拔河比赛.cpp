#include<stdio.h>
int main()
{
    int T,a[6],sum=0,i,j,k,score,flag=0;
    do{
        scanf("%d",&T);
    }while(T<=0);
    while(T--){
        flag=0;
        sum=0;
        for(i=0;i<6;i++){
            do{
                scanf("%d",&a[i]);
            }while(a[i]<=0);
            sum+=a[i];
        }
        for(i=0;i<6;i++)
            for(j=i+1;j<6;j++)
                for(k=j+1;k<6;k++)
                {
                    score=a[i]+a[j]+a[k];
                    if((sum-score)==score)
                    {
                        flag=1;
                        break;
                    }
                }
        if(flag==1)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}

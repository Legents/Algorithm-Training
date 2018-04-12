#include<stdio.h>
int main()
{
    int A,B,i,num=0,sum=0;
    do{
        scanf("%d %d",&A,&B);
    }while(A<-100||A>100||B<-100||B>100||A>B);
    for(i=A;i<=B;i++)
    {
        printf("%5d ",i);
        sum+=i;
        num++;
        if(num==5)
        {
            printf("\n");
            num=0;
        }
    }
    printf("\n");
    printf("Sum = %d",sum);
    return 0;
}

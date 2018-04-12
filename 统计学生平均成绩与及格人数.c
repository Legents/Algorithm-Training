#include<stdio.h>
int main()
{
    int N,count=0,i;
    float average,sum=0;
    do{
        scanf("%d",&N);
    }while(N<0);

    int score[N];
    for(i=0;i<N;i++)
    {
        scanf("%d ",&score[i]);
        sum+=score[i];
        if(score[i]>=60)
            count++;
    }
    average=sum/N;
    printf("average = %.1f\ncount = ",average,count);
    return 0;
}

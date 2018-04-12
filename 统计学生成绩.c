#include<stdio.h>
int main()
{
    int N,i;
    scanf("%d",&N);
    int a=0,b=0,c=0,d=0,e=0;
    int score[N];
    for(i=0;i<N;i++)
    {
        do{
            scanf("%d",&score[i]);
        }while(score[i]<0||score[i]>100);
        switch(score[i]/10){
            case 10:
            case 9:a++;break;
            case 8:b++;break;
            case 7:c++;break;
            case 6:d++;break;
            default:e++;break;
        }
    }
    printf("%d %d %d %d %d",a,b,c,d,e);
    return 0;
}

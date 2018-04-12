#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    long num;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        num=pow(3,i);
        printf("pow(3,%d)=%ld\n",i,num);
    }
    return 0;
}

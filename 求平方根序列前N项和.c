#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    float sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum+=sqrt(i);
    }
    printf("sum = %.2f",sum);
    return 0;
}

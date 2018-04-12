#include<stdio.h>
int main()
{
    int n,i,j;
    char ch='A';
    do{
        scanf("%d",&n);
    }while(n<1||n>=7);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
    {
        printf("%c ",ch++);
    }
    printf("\n");
    }
       return 0;
}

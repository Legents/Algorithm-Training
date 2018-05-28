#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int g[15];
struct node
{
    char name[25];
    int grade;
} a[1005];
int cmp(node a,node b)
{
    if(a.grade==b.grade)
     return strcmp(a.name,b.name)<0?1:0; //按字典序升序
    //return a.name<b.name;//不能这么排序
    else
    return a.grade>b.grade;
}
int main()
{
    int n,m,G,p,c;
    while(scanf("%d",&n)!=EOF)
    {
        memset(g,0,sizeof(g));
        //memset(a,0,sizeof(a));
        for(int i=0;i<1005;i++)
        {
            a[i].grade=0;
        }
        int count=0;
        if(n==0)
            break;
        scanf("%d%d",&m,&G);
        for(int i=1; i<=m; i++)
            scanf("%d",&g[i]);
        for(int i=1; i<=n; i++)
        {
            scanf("%s%d",a[i].name,&p);
            for(int j=1; j<=p; j++)
            {
                scanf("%d",&c);
                a[i].grade+=g[c];
               // printf("%d\n",a[i].grade);
            }
            if(a[i].grade>=G)
            count++;
            else
            a[i].grade=-1;
        }
        sort(a+1,a+n+1,cmp);
        printf("%d\n",count);
        for(int i=1;i<=n;i++)
        {
            if(a[i].grade==-1)
            break;
            else
            printf("%s %d\n",a[i].name,a[i].grade);
        }
    }
    return 0;
}

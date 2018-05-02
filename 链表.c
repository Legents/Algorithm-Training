#include <stdio.h>
typedef struct LNode
{
    int data;//data中存放结点数据
    struct LNode *next;//指向后继结点的指针
}LNode,*LinkedList;//定义单链表结点类型

LinkedList creatList(int a[])//创建链表（头插法）
{
    int i;
    LNode *L;
    L=(LNode *)malloc(sizeof(LNode));//申请结点空间
    L->next=NULL;//初始化一个空链表

    int x;//x为链表中储存的数据
    for(i=0;i<=sizeof(a)-1;++i)
    {   x=a[i];
        LNode *p;
        p=(LNode *)malloc(sizeof(LNode));
        p->data = x;//结点数据域赋值
        p->next = L->next;//将结点插入到表头
        L->next = p;
    }
    return L;
}
LinkedList creatList2(int a[])//尾插法创建链表
{
    int i;
    LNode * L;
    L=(LNode *)malloc(sizeof(LNode));//申请头结点空间
    L->next =NULL;
    LNode *r;
    r=L;//r始终指向终端结点，开始时指向头结点

    int x;
    for(i=0;i<=sizeof(a)-1;++i)
    {
        x=a[i];
        LNode *p;
        p = (LNode *)malloc(sizeof(LNode));
        p->data=x;
        r->next=p;
        r = p;
    }
        r->next = NULL;
        return L;
}
LinkedList lkInsert(LinkedList L,int i,int x)//在链表的第i个位置插入x的元素
{
    int j;
    LNode *p;//前驱结点
    p =L;
    LNode *in;
    in->data=x;
    for(j= 1;j<=i-1;++j)
    {
        p=p->next;
    }
    in->next=p->next;
    p->next=in;
    return L;
}
LinkedList lkdelete(LinkedList L,int pos)//删除第p个位置上的元素
{
    int j;
    LNode *p;//前驱结点
    p =L;
    LNode *del;
     for(j= 1;j<=pos-1;++j)
    {
        p=p->next;
    }
    del = p->next;
    p = p->next;
    free(del);
    return L;
    }
    LinkedList lkzdelete(LinkedList L,int x)//删除值为x的元素
    {
        LNode *p;//前驱结点
    p =L;
    LNode *de;
    de = p->next;
    LNode *del;
    while(L->next!=NULL)
    {
        if(de->data!=x)
            p=p->next;
        else
            del = p->next;
        p = p->next;
        free(del);
        continue;
    }
     return L;
    }
    void print(LNode *L)
    {
         LNode *p;//前驱结点
         p =L;
        while(p->next!=NULL)
        {
            printf("%d  ",p->data);
        }
        printf("\n");
    }
    int main()
    {   int a[5]={1,2,3,4,5};
        LinkedList L =  creatList2(a[5]);
        print(L);
        lkInsert(L,3,87);
        print(L);
        lkdelete(L,3);
        print(L);
        printf("按元素值删除\n");
         print(L);
        lkInsert(L,3,87);
        print(L);
        lkzdelete(L,87);
        print(L);
        return 0;
    }

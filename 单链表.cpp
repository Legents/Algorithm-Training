#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void InitList(LinkList *h)//初始化链表 
{
    int i;
    *h=(LinkList)malloc(sizeof(LNode));
    if(!h)//判断是否为h分配到所需空间 
        {
            printf("初始化链表错误！\n");
            exit(0);
        }
    (*h)->next=NULL;
    for(i=0;i<5;i++)//初始化 
    {
        LinkList s;
        s=(LinkList)malloc(sizeof(LNode));
        s->data=(i+1);
        s->next=(*h)->next;
        (*h)->next=s;
    }
}
void PrintList(LinkList *h)//打印链表 
{

    if((*h)->next==NULL)
    {
        printf("链表为空 不能输出\n");
        exit(0);
    }
    LinkList p;
    p=(LinkList)malloc(sizeof(LNode));
    p=(*h)->next;
    while(p)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
}
void InsertList(LinkList *h,int pos,int item)//插入元素 
{
    LinkList p=*h;
    int i=0;
    while(p&&i<pos-1)//寻找所需插入的位置 
    {
        p=p->next;
        i++;
    }
    if(!p||i>pos-1)//判断插入位置的合法性 
    {
        printf("位置不合法\n");
        exit(0);
    }
    LinkList q;
    q=(LinkList)malloc(sizeof(LNode));
    if(!q)//判断是否分配到空间 
    {
        printf("插入失败\n");
        exit(0);
    }
    q->next=p->next;
    q->data=item;
    p->next=q;
}
void DeleteList(LinkList *h,int pos)
{
     LinkList p=*h;
    int i=0;
    while(p->next&&i<pos-1)//寻找要删除的位置 
    {
        p=p->next;
        i++;
    }
    LinkList q;
    if(!p->next||i>pos-1)
    {
        printf("删除位置不合法\n");
        exit(0);
    }
    q=p->next;
    p->next=q->next;
    free(q);

}
int main()
{
    LinkList h;
    int x;
    printf("请选择：\n 1:初始化链表\n 2:插入元素\n 3:删除元素\n 0:退出\n");
    while(scanf("%d",&x)&&x!=0){
    	switch(x){
		case 1:InitList(&h);
			   printf("初始化后的链表为：\n");
    		   PrintList(&h);
    		   break;
    	case 2:InsertList(&h,3,6);
    		   printf("插入元素后的链表为：\n");
    		   PrintList(&h);
    		   break;
    	case 3:DeleteList(&h,3);
    		   printf("删除元素后的链表为：\n"); 
    		   PrintList(&h);
    		   break;
    	default:exit(0);
	} 
	}
	
    return 0;
}

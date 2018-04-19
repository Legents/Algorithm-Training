#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void InitList(LinkList *h)//��ʼ������ 
{
    int i;
    *h=(LinkList)malloc(sizeof(LNode));
    if(!h)//�ж��Ƿ�Ϊh���䵽����ռ� 
        {
            printf("��ʼ���������\n");
            exit(0);
        }
    (*h)->next=NULL;
    for(i=0;i<5;i++)//��ʼ�� 
    {
        LinkList s;
        s=(LinkList)malloc(sizeof(LNode));
        s->data=(i+1);
        s->next=(*h)->next;
        (*h)->next=s;
    }
}
void PrintList(LinkList *h)//��ӡ���� 
{

    if((*h)->next==NULL)
    {
        printf("����Ϊ�� �������\n");
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
void InsertList(LinkList *h,int pos,int item)//����Ԫ�� 
{
    LinkList p=*h;
    int i=0;
    while(p&&i<pos-1)//Ѱ����������λ�� 
    {
        p=p->next;
        i++;
    }
    if(!p||i>pos-1)//�жϲ���λ�õĺϷ��� 
    {
        printf("λ�ò��Ϸ�\n");
        exit(0);
    }
    LinkList q;
    q=(LinkList)malloc(sizeof(LNode));
    if(!q)//�ж��Ƿ���䵽�ռ� 
    {
        printf("����ʧ��\n");
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
    while(p->next&&i<pos-1)//Ѱ��Ҫɾ����λ�� 
    {
        p=p->next;
        i++;
    }
    LinkList q;
    if(!p->next||i>pos-1)
    {
        printf("ɾ��λ�ò��Ϸ�\n");
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
    printf("��ѡ��\n 1:��ʼ������\n 2:����Ԫ��\n 3:ɾ��Ԫ��\n 0:�˳�\n");
    while(scanf("%d",&x)&&x!=0){
    	switch(x){
		case 1:InitList(&h);
			   printf("��ʼ���������Ϊ��\n");
    		   PrintList(&h);
    		   break;
    	case 2:InsertList(&h,3,6);
    		   printf("����Ԫ�غ������Ϊ��\n");
    		   PrintList(&h);
    		   break;
    	case 3:DeleteList(&h,3);
    		   printf("ɾ��Ԫ�غ������Ϊ��\n"); 
    		   PrintList(&h);
    		   break;
    	default:exit(0);
	} 
	}
	
    return 0;
}

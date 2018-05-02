#include <stdio.h>
typedef struct LNode
{
    int data;//data�д�Ž������
    struct LNode *next;//ָ���̽���ָ��
}LNode,*LinkedList;//���嵥����������

LinkedList creatList(int a[])//��������ͷ�巨��
{
    int i;
    LNode *L;
    L=(LNode *)malloc(sizeof(LNode));//������ռ�
    L->next=NULL;//��ʼ��һ��������

    int x;//xΪ�����д��������
    for(i=0;i<=sizeof(a)-1;++i)
    {   x=a[i];
        LNode *p;
        p=(LNode *)malloc(sizeof(LNode));
        p->data = x;//���������ֵ
        p->next = L->next;//�������뵽��ͷ
        L->next = p;
    }
    return L;
}
LinkedList creatList2(int a[])//β�巨��������
{
    int i;
    LNode * L;
    L=(LNode *)malloc(sizeof(LNode));//����ͷ���ռ�
    L->next =NULL;
    LNode *r;
    r=L;//rʼ��ָ���ն˽�㣬��ʼʱָ��ͷ���

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
LinkedList lkInsert(LinkedList L,int i,int x)//������ĵ�i��λ�ò���x��Ԫ��
{
    int j;
    LNode *p;//ǰ�����
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
LinkedList lkdelete(LinkedList L,int pos)//ɾ����p��λ���ϵ�Ԫ��
{
    int j;
    LNode *p;//ǰ�����
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
    LinkedList lkzdelete(LinkedList L,int x)//ɾ��ֵΪx��Ԫ��
    {
        LNode *p;//ǰ�����
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
         LNode *p;//ǰ�����
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
        printf("��Ԫ��ֵɾ��\n");
         print(L);
        lkInsert(L,3,87);
        print(L);
        lkzdelete(L,87);
        print(L);
        return 0;
    }

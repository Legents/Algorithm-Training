#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int a1, a2, a3;//�ֱ��ʾÿһ���ϵ��
	struct Node *next;
}Node,*LinkList;
void InitList(LinkList *h)//��ʼ������
{
	*h = (LinkList)malloc(sizeof(Node));
	if (!h)//�ж��Ƿ�Ϊh���䵽����ռ�
	{
		printf("��ʼ���������\n");
		exit(0);
	}
	(*h)->next = NULL;
}
void InsertList(LinkList *h, int a1, int a2, int a3)//�������ϵ�����뵽��ǰ������ {
{	LinkList s;
	s = (LinkList)malloc(sizeof(Node));
	s->a1 = a1;
	s->a2 = a2;
	s->a3 = a3;
	s->next = (*h)->next;
	(*h)->next = s;
}
int main() {
	LinkList h;
	InitList(&h);
	int n,a1,a2,a3,i,sum1=0,sum2=0,sum3=0;
	printf("������Ҫ�ϲ��Ķ���ʽ�ĸ���:\n");
	scanf("%d", &n);
	printf("��ֱ���������һ�����Լ��������ϵ��:\n");
	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &a1, &a2, &a3);
		InsertList(&h, a1, a2, a3);
	}
	LinkList p;
	p = (LinkList)malloc(sizeof(Node));
	p = h->next;
	while (p)//�ֱ�Ը���ϵ�����
	{
		sum1 += p->a1;
		sum2 += p->a2;
		sum3 += p->a3;
		p = p->next;
	}
	printf("�ϲ���Ķ���ʽΪ��\n");
	printf("%dX^2+%dX+%d\n", sum1, sum2, sum3);
	system("pause");
	return 0;
}

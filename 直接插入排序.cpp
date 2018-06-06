#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node *next;
}Node,*LinkList;
LinkList InitList() {
	LinkList p;
	p = (LinkList)malloc(sizeof(Node));
	if (!p) {
		printf("��ʼ��ʧ�ܣ�\n");
		exit(0);
	}
	p->next = NULL;
	return p;
}
LinkList Insert(LinkList p, int data) {
	LinkList q = p;
	LinkList s = (LinkList)malloc(sizeof(Node));
	s->data = data;
	s->next = NULL;
	if (!q->next) {//������Ϊ��ʱ��ֱ�Ӳ��뵽ͷ�ڵ�֮�� 
		q->next = s;
	}
	else
	{
		while (q&&q->next) {//���Ҳ����λ�� 
			if (data < q->next->data) {//Ԫ�ش�С�������򣬵��Ƚϵ���һ���ڵ����Ҫ����Ľڵ�ʱ���в��� 
				s->next = q->next;
				q->next = s;
				return p;
			}
			q = q->next;
		}
		if (!q->next) {//����Ƚϵ����һ����û�бȵ�ǰ�������뵽��� 
			q->next = s;
			return p;
		}	
	}
}
void PrintList(LinkList h)//��ӡ���� 
{
	if (h->next == NULL)
	{
		printf("����Ϊ�� �������\n");
		exit(0);
	}
	LinkList p;
	p = (LinkList)malloc(sizeof(Node));
	p = h->next;
	while (p)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}
int main() {
	LinkList p = InitList();
	int num;
	printf("���������ڵ�ĸ�����\n");
	scanf("%d", &num);
	int i,n;
	printf("������ÿ���ڵ��ֵ��\n");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &n);
		Insert(p, n);
	}
	printf("ѡ���������������Ϊ��\n");
	PrintList(p);
	system("pause");
	return 0;
}

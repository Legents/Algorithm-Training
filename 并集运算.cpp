#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node *next;
}Node,*LinkList;
LinkList InitList() {
	LinkList h;
	h = (LinkList)malloc(sizeof(Node));
	if (!h) {
		printf("�ڴ����ʧ�ܣ�\n");
		system("pause");
		exit(0);
	}
	h->next = NULL;
	return h;
}
void InsertList(LinkList h, int pos, int item) {
	int i=0;
	LinkList p = h;
	while (p&&i < pos - 1) {
		p = p->next;
		i++;
	}
	if (!p || i>pos - 1)//�жϲ���λ�õĺϷ��� 
	{
		printf("λ�ò��Ϸ�\n");
		system("pause");
		exit(0);
	}
	LinkList q;
	q = (LinkList)malloc(sizeof(Node));
	if (!q)//�ж��Ƿ���䵽�ռ� 
	{
		printf("����ʧ��\n");
		system("pause");
		exit(0);
	}
	q->data = item;
	q->next = p->next;
	p->next = q;
}
void Print(LinkList h) {
	if (h->next == NULL)
	{
		printf("����Ϊ�� �������\n");
		system("pause");
		exit(0);
	}
	LinkList p = h->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void unionSet(LinkList h, LinkList m, LinkList n) {
	LinkList p, q, s, r;
	int i = 1;
	p =m->next;
	q = n->next;
	s = h;
	while (p) {
		while (q) {
			if (p->data == q->data)
			{
				InsertList(s, i, p->data);
				q = n->next;
				i++;
				break;
			}
			else
				q = q->next;
			if (!q) {
				q = n->next;
			}
		}
		p = p->next;
	}
	Print(s);
}
int main() {
	LinkList h,m,n;
	h=InitList();
	m=InitList();
	n=InitList();
	for(int i=0;i<5;i++)
		InsertList(m, i+1,i+1);
	printf("m:\n");
	Print(m);
	for (int i = 0; i<5; i++)
		InsertList(n, i + 1, i + 3);
	printf("n:\n");
	Print(n);
	unionSet(h, m, n);
	printf("h:\n");
	Print(h);
	system("pause");
	return 0;

}
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int a1, a2;//�ֱ��ʾϵ��������
	struct Node *next;
}Node,*LinkList;
LinkList InitList()//��ʼ������
{
	LinkList h;
	h = (LinkList)malloc(sizeof(Node));
	if (!h)//�ж��Ƿ�Ϊh���䵽����ռ�
	{
		printf("��ʼ���������\n");
		exit(0);
	}
	h->next = NULL;
	return h;
}
void InsertList(LinkList h, int a1, int a2)//�������ϵ�����뵽��ǰ������ 
{	
	
		LinkList p, s;
		s = (LinkList)malloc(sizeof(Node));
		s->a1 = a1;
		s->a2 = a2;
		p = h;
		s->next = p->next;
		p->next = s;
}
/*LinkList InsertSort(LinkList h) {
	if (h == NULL || h->next == NULL) {
		return h;
	}
	LinkList p = h->next;
	while (p) {
		if (p->a2 < h->a2) {
			LinkList temp1 = h;
			while (temp1->next != p) {
				temp1 = temp1->next;
			}
			LinkList temp = p;
			p = p->next;
			temp1->next = p;
			temp->next = h;
			h = temp;
			continue;
		}
		LinkList q = h;
		while (q->next != p) {
			if (q->next->a2 < p->a2) {
				q = q->next;
			}
			else
				break;
		}
		if (q->next == p) {
			p = p->next;
		}
		else {
			LinkList temp1 = q;
			while (temp1->next != q) {
				temp1 = temp1->next;
			}
			LinkList temp = p;
			p = p->next;
			temp1->next = p;
			temp->next = q->next;
			q->next = temp;
		}
	}
	return h;
}*/
void Print(LinkList h) {
	LinkList p = h->next;
	while (p) {
		printf("%d %d\n", p->a1,p->a2);
		p = p->next;
	}
	printf("\n");
}
int main() {
	LinkList h;
	h=InitList();
	int a1,a2;
	printf("�ֱ�����ÿһ���ϵ������������0��0������\n");
	do {
		scanf("%d %d", &a1, &a2);
		InsertList(h, a1, a2);
	}while (a1 != 0 || a2 != 0);
	Print(h);
	LinkList s;
	s = InitList();
	s= InsertSort(h);
	Print(s);
	printf("�ϲ���Ķ���ʽΪ��\n");
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	float a1;//ϵ��
	int a2;//ָ��
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
void Sort(LinkList h,int n) {//�Բ�����ϵ�������ָ���Ӵ�С��˳���������
	int i, j, t2;
	float t1;
	LinkList p=h, q;
	for (i = 0; i < n; i++) {
		p = p->next;
		q = p;
		for (j = i + 1; j < n; j++) {
			q = q->next;
			if (p->a2 < q->a2) {
				t1 = p->a1;
				t2 = p->a2;
				p->a1 = q->a1;
				p->a2 = q->a2;
				q->a1 = t1;
				q->a2 = t2;
			}
		}
	}
}
void Add1(LinkList h) {//��������ϵ����������ָͬ����ϲ�
	LinkList p = h->next;
	while (p->next) {
		if (p->a2 == p->next->a2) {
			p->a1 += p->next->a1;
			LinkList s = (LinkList)malloc(sizeof(Node));
			s = p->next;
			p->next = p->next->next;
			free(s);
		}
		else p = p->next;
	}
}
void ConnectList(LinkList h1, LinkList h2) {//�������ϲ���ϵ��������������γ����֮���ʼ������
	LinkList p = h1->next;
	while (p->next) {
		p = p->next;
	}
	p->next = h2->next;
}
int ListLength(LinkList h1) {//��ȡ������
	LinkList p = h1->next;
	int total = 0;
	while (p) {
		total++;
		p = p->next;
	}
	return  total;
}
void Print(LinkList h) {//�������ʽ���п���
	LinkList p = h->next;
	while (p) {
		if (p->a1 > 1){
			if (p->a2 > 1) {//���ϵ����ָ��������1���������
				printf("%.2fX^%d", p->a1, p->a2);
				if (p->next != NULL)
					printf(" + ");
			}
			else if (p->a2 == 1) {//���ָ��Ϊ1�� ϵ��*X �ĸ�ʽ���
				printf("%.2fX", p->a1);
				if (p->next != NULL)
					printf(" + ");
			}
			else {//���ָ��Ϊ0 ��ֻ���ϵ������������
				printf("%.2f", p->a1);
				if (p->next != NULL)
					printf(" + ");
			}
		}
		else if (p->a1 == 1) {//���ϵ��Ϊ1 �����ϵ��ֱ�����X����ָ��
			if (p->a2 > 1) {
				printf("X^%d", p->a2);
				if (p->next != NULL)
					printf(" + ");
			}
			else if (p->a2 == 1) {
				printf("X");
				if (p->next != NULL)
					printf(" + ");
			}
			else if (p->a2 == 0) {//���ָ��Ϊ0 ��ֻ���ϵ��1
				printf("1.00");
				if (p->next != NULL)
					printf(" + ");
			}
		}	
		p = p->next;
	}
	printf("\n");
}
int main() {
	LinkList h1,h2;
	h1 = InitList();
	h2 = InitList();
	float a1;
	int a2,n=0,m=0;
	printf("�ֱ������һ������ʽÿһ���ϵ������������0��0������\n");
	do {
		scanf("%f %d", &a1, &a2);
		if (a1 != 0 || a2 != 0) {
			InsertList(h1, a1, a2);
			n++;
		}
	}while (a1 != 0 || a2 != 0);
	printf("����ĵ�һ������ʽΪ��\n");
	Print(h1);
	Sort(h1, n);
	printf("����ĵ�һ������ʽ�����Ϊ��\n");
	Print(h1);
	Add1(h1);
	printf("����ĵ�һ������ʽ�ڲ��ϲ���Ϊ��\n");
	Print(h1);

	printf("�ֱ�����ڶ�������ʽÿһ���ϵ������������0��0������\n");
	do {
		scanf("%f %d", &a1, &a2);
		if (a1 != 0 || a2 != 0) {
			InsertList(h2, a1, a2);
			m++;
		}
	} while (a1 != 0 || a2 != 0);
	printf("����ĵڶ�������ʽΪ��\n");
	Print(h2);
	Sort(h2, m);
	printf("����ĵڶ�������ʽ�����Ϊ��\n");
	Print(h2);
	Add1(h2);
	printf("����ĵڶ�������ʽ�ڲ��ϲ���Ϊ��\n");
	Print(h2);
	ConnectList(h1, h2);//������ϲ����h1��h2����
	int total = ListLength(h1);//��ȡ���Ӻ��������ĳ���
	Sort(h1, total);//�����Ӻ�������������
	Add1(h1);//�ڲ�ָ����ͬ�����
	printf("�ϲ���Ķ���ʽΪ��\n");
	Print(h1);
	system("pause");
	return 0;
}

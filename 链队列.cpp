#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node *next;
}LNode,*PNode;
typedef struct {
	PNode front, rear;
}LinkQuene;
int InitQuene(LinkQuene *Q);//���г�ʼ��
void EnQuene(LinkQuene *Q, int n);//���
void Print(LinkQuene *Q);//��ӡ����Ԫ��
void DeQuene(LinkQuene *Q);//����
int main()
{
	int i,c;
	LinkQuene Q;
	InitQuene(&Q);
	printf("1:���\n2:����\n0:�˳�\n");
	while (scanf("%d", &c) && c != 0)
	{
		switch (c) {
		case 1:for (i = 0; i < 5; i++)
					EnQuene(&Q, i + 1);
				printf("��Ӻ��������Ϊ��\n");
			    Print(&Q);
				break;
		case 2:DeQuene(&Q);
			   printf("���Ӻ��������Ϊ��\n");
			   Print(&Q);
			   break;
		default:system("pause");
			    exit(0);
		}
	}
	system("pause");
	return 0;
}
int InitQuene(LinkQuene *Q)//���г�ʼ��
{
	Q->front = Q->rear = (PNode)malloc(sizeof(LNode));
	if (!Q->front) {
		printf("���г�ʼ��ʧ�ܣ�\n");
		system("pause");
		return 0;
	}
	return 1;
}
void EnQuene(LinkQuene *Q, int n)//���
{
	PNode p;
	p = (PNode)malloc(sizeof(LNode));
	if (!p) {
		printf("���ʧ�ܣ�\n");
		system("pause");
		exit(0);
	}
	p->data = n;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}
void Print(LinkQuene *Q)//��ӡ����Ԫ��
{
	PNode p;
	p = (PNode)malloc(sizeof(LNode));
	p = Q->front->next;
	if (Q->front == Q->rear) {
		printf("����Ϊ�գ����������\n");
		system("pause");
		exit(0);
	}
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void DeQuene(LinkQuene *Q)//����
{
	PNode p;
	p = (PNode)malloc(sizeof(LNode));
	if (Q->front->next == Q->rear->next)
	{
		printf("������Ϊ�գ����ܳ���!\n");
		system("pause");
		exit(0);
	}
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
}
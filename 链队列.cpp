#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node *next;
}LNode,*PNode;
typedef struct {
	PNode front, rear;
}LinkQuene;
int InitQuene(LinkQuene *Q);//队列初始化
void EnQuene(LinkQuene *Q, int n);//入队
void Print(LinkQuene *Q);//打印队列元素
void DeQuene(LinkQuene *Q);//出队
int main()
{
	int i,c;
	LinkQuene Q;
	InitQuene(&Q);
	printf("1:入队\n2:出队\n0:退出\n");
	while (scanf("%d", &c) && c != 0)
	{
		switch (c) {
		case 1:for (i = 0; i < 5; i++)
					EnQuene(&Q, i + 1);
				printf("入队后的链队列为：\n");
			    Print(&Q);
				break;
		case 2:DeQuene(&Q);
			   printf("出队后的链队列为：\n");
			   Print(&Q);
			   break;
		default:system("pause");
			    exit(0);
		}
	}
	system("pause");
	return 0;
}
int InitQuene(LinkQuene *Q)//队列初始化
{
	Q->front = Q->rear = (PNode)malloc(sizeof(LNode));
	if (!Q->front) {
		printf("队列初始化失败！\n");
		system("pause");
		return 0;
	}
	return 1;
}
void EnQuene(LinkQuene *Q, int n)//入队
{
	PNode p;
	p = (PNode)malloc(sizeof(LNode));
	if (!p) {
		printf("入队失败！\n");
		system("pause");
		exit(0);
	}
	p->data = n;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}
void Print(LinkQuene *Q)//打印队列元素
{
	PNode p;
	p = (PNode)malloc(sizeof(LNode));
	p = Q->front->next;
	if (Q->front == Q->rear) {
		printf("队列为空，不能输出！\n");
		system("pause");
		exit(0);
	}
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void DeQuene(LinkQuene *Q)//出队
{
	PNode p;
	p = (PNode)malloc(sizeof(LNode));
	if (Q->front->next == Q->rear->next)
	{
		printf("链队列为空，不能出队!\n");
		system("pause");
		exit(0);
	}
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
}
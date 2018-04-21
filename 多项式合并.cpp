#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int a1, a2, a3;//分别表示每一项的系数
	struct Node *next;
}Node,*LinkList;
void InitList(LinkList *h)//初始化链表
{
	*h = (LinkList)malloc(sizeof(Node));
	if (!h)//判断是否为h分配到所需空间
	{
		printf("初始化链表错误！\n");
		exit(0);
	}
	(*h)->next = NULL;
}
void InsertList(LinkList *h, int a1, int a2, int a3)//将输入的系数插入到当前链表中 {
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
	printf("输入你要合并的多项式的个数:\n");
	scanf("%d", &n);
	printf("请分别输入二次项，一次项以及常数项的系数:\n");
	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &a1, &a2, &a3);
		InsertList(&h, a1, a2, a3);
	}
	LinkList p;
	p = (LinkList)malloc(sizeof(Node));
	p = h->next;
	while (p)//分别对各项系数求和
	{
		sum1 += p->a1;
		sum2 += p->a2;
		sum3 += p->a3;
		p = p->next;
	}
	printf("合并后的多项式为：\n");
	printf("%dX^2+%dX+%d\n", sum1, sum2, sum3);
	system("pause");
	return 0;
}

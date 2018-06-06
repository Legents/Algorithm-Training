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
		printf("初始化失败！\n");
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
	if (!q->next) {//当链表为空时，直接插入到头节点之后 
		q->next = s;
	}
	else
	{
		while (q&&q->next) {//查找插入的位置 
			if (data < q->next->data) {//元素从小到大排序，当比较到后一个节点大于要插入的节点时进行插入 
				s->next = q->next;
				q->next = s;
				return p;
			}
			q = q->next;
		}
		if (!q->next) {//如果比较到最后一个都没有比当前大的则插入到最后 
			q->next = s;
			return p;
		}	
	}
}
void PrintList(LinkList h)//打印链表 
{
	if (h->next == NULL)
	{
		printf("链表为空 不能输出\n");
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
	printf("请输入插入节点的个数：\n");
	scanf("%d", &num);
	int i,n;
	printf("请输入每个节点的值：\n");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &n);
		Insert(p, n);
	}
	printf("选择排序结束的链表为：\n");
	PrintList(p);
	system("pause");
	return 0;
}

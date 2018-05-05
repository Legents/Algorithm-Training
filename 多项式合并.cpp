#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int a1, a2;//分别表示系数和幂数
	struct Node *next;
}Node,*LinkList;
LinkList InitList()//初始化链表
{
	LinkList h;
	h = (LinkList)malloc(sizeof(Node));
	if (!h)//判断是否为h分配到所需空间
	{
		printf("初始化链表错误！\n");
		exit(0);
	}
	h->next = NULL;
	return h;
}
void InsertList(LinkList h, int a1, int a2)//将输入的系数插入到当前链表中 
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
	printf("分别输入每一项的系数和幂数，以0，0结束：\n");
	do {
		scanf("%d %d", &a1, &a2);
		InsertList(h, a1, a2);
	}while (a1 != 0 || a2 != 0);
	Print(h);
	LinkList s;
	s = InitList();
	s= InsertSort(h);
	Print(s);
	printf("合并后的多项式为：\n");
	system("pause");
	return 0;
}

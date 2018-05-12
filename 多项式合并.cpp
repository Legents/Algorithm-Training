#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	float a1;//系数
	int a2;//指数
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
void Sort(LinkList h,int n) {//对插入完毕的链表按照指数从大到小的顺序进行排序
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
void Add1(LinkList h) {//对排序完毕的链表进行相同指数项合并
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
void ConnectList(LinkList h1, LinkList h2) {//将独立合并完毕的两个链表连接形成求和之后初始的链表
	LinkList p = h1->next;
	while (p->next) {
		p = p->next;
	}
	p->next = h2->next;
}
int ListLength(LinkList h1) {//获取链表长度
	LinkList p = h1->next;
	int total = 0;
	while (p) {
		total++;
		p = p->next;
	}
	return  total;
}
void Print(LinkList h) {//对输出格式进行控制
	LinkList p = h->next;
	while (p) {
		if (p->a1 > 1){
			if (p->a2 > 1) {//如果系数和指数都大于1则正常输出
				printf("%.2fX^%d", p->a1, p->a2);
				if (p->next != NULL)
					printf(" + ");
			}
			else if (p->a2 == 1) {//如果指数为1则按 系数*X 的格式输出
				printf("%.2fX", p->a1);
				if (p->next != NULL)
					printf(" + ");
			}
			else {//如果指数为0 则只输出系数，即常数项
				printf("%.2f", p->a1);
				if (p->next != NULL)
					printf(" + ");
			}
		}
		else if (p->a1 == 1) {//如果系数为1 则不输出系数直接输出X及其指数
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
			else if (p->a2 == 0) {//如果指数为0 则只输出系数1
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
	printf("分别输入第一个多项式每一项的系数和幂数，以0，0结束：\n");
	do {
		scanf("%f %d", &a1, &a2);
		if (a1 != 0 || a2 != 0) {
			InsertList(h1, a1, a2);
			n++;
		}
	}while (a1 != 0 || a2 != 0);
	printf("输入的第一个多项式为：\n");
	Print(h1);
	Sort(h1, n);
	printf("输入的第一个多项式排序后为：\n");
	Print(h1);
	Add1(h1);
	printf("输入的第一个多项式内部合并后为：\n");
	Print(h1);

	printf("分别输入第二个多项式每一项的系数和幂数，以0，0结束：\n");
	do {
		scanf("%f %d", &a1, &a2);
		if (a1 != 0 || a2 != 0) {
			InsertList(h2, a1, a2);
			m++;
		}
	} while (a1 != 0 || a2 != 0);
	printf("输入的第二个多项式为：\n");
	Print(h2);
	Sort(h2, m);
	printf("输入的第二个多项式排序后为：\n");
	Print(h2);
	Add1(h2);
	printf("输入的第二个多项式内部合并后为：\n");
	Print(h2);
	ConnectList(h1, h2);//将排序合并后的h1和h2连接
	int total = ListLength(h1);//获取连接后的新链表的长度
	Sort(h1, total);//将连接后的链表进行排序
	Add1(h1);//内部指数相同项相加
	printf("合并后的多项式为：\n");
	Print(h1);
	system("pause");
	return 0;
}

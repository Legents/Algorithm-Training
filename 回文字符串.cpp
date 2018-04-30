#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	char c;
	struct Node *next;
}Node,*LNode;
typedef struct {
	LNode front,rear;
}LinkQuene;
int InitQuene(LinkQuene *h) {
	h->front = h->rear = (LNode)malloc(sizeof(LNode));
	if (!h->front) {
		printf("��ʼ������\n");
		system("pause");
		return 0;
	}
	return 1;
}
void EnQuene(LinkQuene *h, LinkQuene *q,char c) {
	LNode p;
	p = (LNode)malloc(sizeof(LNode));
	if (!p) {
		printf("���ʧ�ܣ�\n");
		system("pause");
		exit(0);
	}
	p->c = c;
	p->next = NULL;
	h->rear->next = p;
	h->rear = p;
	p->next = NULL;
	q->front->next = p;
	q->front = p;
}
int compare(LinkQuene *h, LinkQuene *q) {
	LNode m, n;
	m = h->front->next;
	n = q->front->next;
	while (m != NULL && n != NULL) {
		if (m->c == n->c) 
			continue;
		else
			return 0;
	}
	return 1;
}
int main() {
	char c;
	LinkQuene h,q;
	InitQuene(&h);
	InitQuene(&q);
	while (scanf("%c", &c) && c != '\n') {
		EnQuene(&h, &q, c);
	}
	if (!compare(&h, &q))
		printf("���ַ����ǻ��Ĵ���\n");
	else
		printf("���ַ������ǻ��Ĵ�\n");
	system("pause");
	return 0;
}
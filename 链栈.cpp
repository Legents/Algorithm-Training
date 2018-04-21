#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
struct Node *next;
}Node, *LinkStack;
void InitStack(LinkStack *top);//��ʼ����ջ
void Push(LinkStack *top,int i);//��ջ
void Print(LinkStack *top);//�Զ����´�ӡջ��Ԫ��
void Pop(LinkStack *top);//��ջ
int main() {
	LinkStack top;
	int c,i;
	InitStack(&top);
	printf("1:��ջ\n2:��ջ\n0:�˳�\n");
	while (scanf("%d", &c) && c != 0) {
		switch (c) {
		case 1:for (i = 0; i < 5; i++)
					Push(&top, i + 1);
			   Print(&top);
			   break;
		case 2:Pop(&top);
			   Print(&top);
			   break;
		default:system("pause");
			    return 0;
		}
	}
	system("pause");
	return 0;
}
void InitStack(LinkStack *top) {//��ʼ����ջ
	*top = (LinkStack)malloc(sizeof(Node));
	if (*top == NULL) {
		printf("��ʼ����ջ����!\n");
		system("pause");
		exit(0);
	}
	(*top)->next = NULL;
}
void Push(LinkStack *top,int i)//��ջ
{
		LinkStack s;
		s = (LinkStack)malloc(sizeof(Node));
		if (!s) {
			printf("��ջ����\n");
			system("pause");
			exit(0);
		}
		s->data = i;
		s->next = (*top)->next;
		(*top)->next = s;
}
void Print(LinkStack *top) {//�Զ����´�ӡջ��Ԫ��
	if ((*top)->next == NULL) {
		printf("��ջΪ�գ����������\n");
		system("pause");
		exit(0);
	}
	LinkStack s;
	s = (LinkStack)malloc(sizeof(Node));
	s = (*top)->next;
	printf("��ջ�Զ����µ�Ԫ��Ϊ��\n");
	while (s) {
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
}
void Pop(LinkStack *top) {//��ջ
	if ((*top)->next == NULL) {
		printf("��ջΪ�գ�������ɳ�ջ������\n");
		system("pause");
		exit(0);
	}
	LinkStack s;
	s = (LinkStack)malloc(sizeof(Node));
	s = (*top)->next;
	(*top)->next = s->next;
	free(s);
}

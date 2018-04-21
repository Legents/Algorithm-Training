#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
struct Node *next;
}Node, *LinkStack;
void InitStack(LinkStack *top);//初始化链栈
void Push(LinkStack *top,int i);//入栈
void Print(LinkStack *top);//自顶向下打印栈顶元素
void Pop(LinkStack *top);//出栈
int main() {
	LinkStack top;
	int c,i;
	InitStack(&top);
	printf("1:入栈\n2:出栈\n0:退出\n");
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
void InitStack(LinkStack *top) {//初始化链栈
	*top = (LinkStack)malloc(sizeof(Node));
	if (*top == NULL) {
		printf("初始化链栈出错!\n");
		system("pause");
		exit(0);
	}
	(*top)->next = NULL;
}
void Push(LinkStack *top,int i)//入栈
{
		LinkStack s;
		s = (LinkStack)malloc(sizeof(Node));
		if (!s) {
			printf("入栈错误！\n");
			system("pause");
			exit(0);
		}
		s->data = i;
		s->next = (*top)->next;
		(*top)->next = s;
}
void Print(LinkStack *top) {//自顶向下打印栈顶元素
	if ((*top)->next == NULL) {
		printf("链栈为空，不能输出！\n");
		system("pause");
		exit(0);
	}
	LinkStack s;
	s = (LinkStack)malloc(sizeof(Node));
	s = (*top)->next;
	printf("链栈自顶向下的元素为：\n");
	while (s) {
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
}
void Pop(LinkStack *top) {//出栈
	if ((*top)->next == NULL) {
		printf("链栈为空，不能完成出栈操作！\n");
		system("pause");
		exit(0);
	}
	LinkStack s;
	s = (LinkStack)malloc(sizeof(Node));
	s = (*top)->next;
	(*top)->next = s->next;
	free(s);
}

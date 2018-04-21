#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100
typedef struct {
	int a[STACKSIZE];
	int top;
}SqStack;
void InitStack(SqStack *S);//初始化顺序栈
int Push(SqStack *S, int n);//入栈
int Pop(SqStack *S);//出栈
void Print(SqStack *S);//打印栈内元素
int main()
{
	int i;
	SqStack S;
	InitStack(&S);
	printf("顺序栈初始化完成\n");
	for (i = 0; i < 5; i++)
		Push(&S, i + 1);
	printf("插入元素之后的堆栈序列为:\n");
	Print(&S);
	Pop(&S);
	printf("元素出栈后的堆栈序列为:\n");
	Print(&S);
	system("pause");
	return 0;
}
void InitStack(SqStack *S)//初始化顺序栈
{
	S->top = -1;
}
int Push(SqStack *S, int n) //入栈
{
	if (S->top == STACKSIZE - 1) {
		printf("顺序栈已满，无法插入元素\n");
		return 0;
	}
	S->top++;
	S->a[S->top] = n;
	return 1;
}
int Pop(SqStack *S) //出栈
{
	if (S->top <= -1) {
		printf("堆栈为空，不能出栈\n");
		return 0;
	}
	S->top--;
	return 1;
}
void Print(SqStack *S) //打印栈内元素
{
	int i;
	for (i = 0; i <= S->top; i++)
		printf("%d ", S->a[i]);
	printf("\n");
}
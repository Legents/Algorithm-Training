#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100
typedef struct {
	int a[STACKSIZE];
	int top;
}SqStack;
void InitStack(SqStack *S);//��ʼ��˳��ջ
int Push(SqStack *S, int n);//��ջ
int Pop(SqStack *S);//��ջ
void Print(SqStack *S);//��ӡջ��Ԫ��
int main()
{
	int i;
	SqStack S;
	InitStack(&S);
	printf("˳��ջ��ʼ�����\n");
	for (i = 0; i < 5; i++)
		Push(&S, i + 1);
	printf("����Ԫ��֮��Ķ�ջ����Ϊ:\n");
	Print(&S);
	Pop(&S);
	printf("Ԫ�س�ջ��Ķ�ջ����Ϊ:\n");
	Print(&S);
	system("pause");
	return 0;
}
void InitStack(SqStack *S)//��ʼ��˳��ջ
{
	S->top = -1;
}
int Push(SqStack *S, int n) //��ջ
{
	if (S->top == STACKSIZE - 1) {
		printf("˳��ջ�������޷�����Ԫ��\n");
		return 0;
	}
	S->top++;
	S->a[S->top] = n;
	return 1;
}
int Pop(SqStack *S) //��ջ
{
	if (S->top <= -1) {
		printf("��ջΪ�գ����ܳ�ջ\n");
		return 0;
	}
	S->top--;
	return 1;
}
void Print(SqStack *S) //��ӡջ��Ԫ��
{
	int i;
	for (i = 0; i <= S->top; i++)
		printf("%d ", S->a[i]);
	printf("\n");
}
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int list[100];
	int length;
}Node,Sqlist;
 void InitList(Sqlist *L) {
	L->length = -1;
}
 int Bi_Search(Sqlist *L, int low, int mid, int high,int data) {
	 if (high >= low) {
		 if (data == L->list[mid])
			 return mid;
		 else if (data < L->list[mid]) {
			 if (mid == (mid + high) / 2)
				 return Bi_Search(L, low, mid + 1, high, data);
			 return Bi_Search(L, low, (mid + low) / 2, mid - 1, data);
		 }
			 
		 else if (data > L->list[mid]) {
			 if (mid == (mid + high) / 2)//������������Ԫ��Ϊ�����б����һ��Ԫ��ʱ���ܳ���low>high֮���εݹ����midֵ��������
				 return Bi_Search(L,low, mid + 1, high, data);//��ʱֱ����lowֵ���䣬midֵ��1����
			 else
				return Bi_Search(L, mid + 1, (mid + high) / 2, high, data);//��ͨ���
		 }
	 }
	 else  if (high < low)
		 return -1; 
}
int main() {
	Sqlist L;
	InitList(&L);
	int a[10] = { 10,32,33,54,65,67,69,85,87,98 };
	int i;
	for (i = 0; i < 10; i++) {
		L.list[i] = a[i];
		L.length++;
	}
	for (i = 0; i <= L.length; i++)
		printf("%3d", L.list[i]);
	int s;
	printf("\n������Ҫ���ҵ�Ԫ�أ�\n");
	scanf("%d", &s);
	int loc = Bi_Search(&L, 0, 5, 9, s);
	if (loc == -1)
		printf("����Ԫ�ز����б���\n");
	else
		printf("���ҵ�Ԫ���ڣ�%d\n", loc);
	system("pause");
	return 0;
}
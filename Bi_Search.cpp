#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int list[100];
	int length;
}Node,Sqlist;
 void InitList(Sqlist *L) {
	L->length = -1;
}
 int Bi_Search(Sqlist *L, int low, int high,int data) {
	 if (high >= low) {
		 int mid = (low+high)/2;
		 if(data==L->list[mid])
		 	return mid;
		else if(data<L->list[mid])
			return Bi_Search(L,low,mid-1,data);
		else if(data>L->list[mid])
			return Bi_Search(L,mid+1,high,data);
	 }
	 else 
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
	printf("\n输入需要查找的元素：\n");
	scanf("%d", &s);
	int loc = Bi_Search(&L, 0, 9, s);
	if (loc == -1)
		printf("查找元素不在列表中\n");
	else
		printf("查找的元素在：%d\n", loc);
	system("pause");
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int item;
}SqList;
int main()
{
	int num,i,j;
	SqList list[100];
	printf("请输入序列元素的个数：\n");
	scanf("%d", &num);
	printf("请输入各个元素的值：\n");
	for (i = 0; i < num; i++) {
		scanf("%d", &list[i].item);
	}
	for (i = 0; i < num; i++) {
		int min = i;
		for (j = i + 1; j < num; j++) {
			if (list[j].item < list[min].item)
				min = j;
		}
		if (min != i) {
			SqList temp;
			temp = list[i];
			list[i] = list[min];
			list[min] = temp;
		}
	}
	printf("\n排序后的序列为：\n");
	for (i = 0; i < num; i++)
		printf("%4d", list[i].item);
	printf("\n");
	system("pause");
	return 0;
}
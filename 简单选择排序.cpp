#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int item;
}SqList;
int main()
{
	int num,i,j;
	SqList list[100];
	printf("����������Ԫ�صĸ�����\n");
	scanf("%d", &num);
	printf("���������Ԫ�ص�ֵ��\n");
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
	printf("\n����������Ϊ��\n");
	for (i = 0; i < num; i++)
		printf("%4d", list[i].item);
	printf("\n");
	system("pause");
	return 0;
}
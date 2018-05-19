#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node *left;//������
	struct Node *right;//������
}BTNode,*PBTNode,*BiTreeLink;
BiTreeLink CreatBiTree(int *datas, int pos, int num) {
	PBTNode p;
	if (pos >= num) {//�����±����ж������Ƿ��Ѿ�ȫ���洢��
		return NULL;
	}
	p = (PBTNode)malloc(sizeof(BTNode));
	if (!p) {
		printf("��ʼ������\n");
		return 0;
	}
	p->data = datas[pos];
	p->left = CreatBiTree(datas, pos * 2, num);
	p->right = CreatBiTree(datas, pos * 2 + 1, num);
	return p;
}
void PreOrder(BiTreeLink q) {//ǰ�����
	if (q != NULL) {
		printf("%d ", q->data);
		PreOrder(q->left);
		PreOrder(q->right);
	}
	
}
void InOrder(BiTreeLink q) {//�������
	if (q != NULL) {
		InOrder(q->left);
		printf("%d ", q->data);
		InOrder(q->right);
	}
	
}
void PostOrder(BiTreeLink q) {//�������
	if (q != NULL) {
		PostOrder(q->left);
		PostOrder(q->right);
		printf("%d ", q->data);
	}
}
int main() {
	int datas[21], i;
	for (i = 0; i <=20; i++)
		datas[i] = i;
	BiTreeLink r = CreatBiTree(datas,1, 21);
	PreOrder(r);
	printf("\n");
	InOrder(r);
	printf("\n");
	PostOrder(r);
	printf("\n");
	system("pause");
	return 0;
}
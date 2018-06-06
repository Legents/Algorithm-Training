#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node *left;//左子树
	struct Node *right;//右子树
}BTNode,*PBTNode,*BiTreeLink;
BiTreeLink CreatBiTree(int *datas, int pos, int num) {
	PBTNode p;
	if (pos >= num) {//根据下表来判断数据是否已经全部存储完
		return NULL;
	}
	p = (PBTNode)malloc(sizeof(BTNode));
	if (!p) {
		printf("初始化错误！\n");
		return 0;
	}
	p->data = datas[pos];
	p->left = CreatBiTree(datas, pos * 2, num);
	p->right = CreatBiTree(datas, pos * 2 + 1, num);
	return p;
}
void PreOrder(BiTreeLink q) {//前序遍历
	if (q != NULL) {
		printf("%d ", q->data);
		PreOrder(q->left);
		PreOrder(q->right);
	}
	
}
void InOrder(BiTreeLink q) {//中序遍历
	if (q != NULL) {
		InOrder(q->left);
		printf("%d ", q->data);
		InOrder(q->right);
	}
	
}
void PostOrder(BiTreeLink q) {//后序遍历
	if (q != NULL) {
		PostOrder(q->left);
		PostOrder(q->right);
		printf("%d ", q->data);
	}
}
int main() {
	int datas[15], i;
	for (i = 0; i <=14; i++)
		datas[i] = i;
	BiTreeLink r = CreatBiTree(datas,1, 15);
	printf("先序：\n");
	PreOrder(r);
	printf("\n");
	printf("中序：\n");
	InOrder(r);
	printf("\n");
	printf("后序：\n");
	PostOrder(r);
	printf("\n");
	system("pause");
	return 0;
}

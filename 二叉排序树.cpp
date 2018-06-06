#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node *left;//左子树
	struct Node *right;//右子树
}BTNode, *PBTNode, *BiTreeLink;
BiTreeLink CreatBiTree(BiTreeLink root, int n) {
	PBTNode p = root, r = (PBTNode)malloc(sizeof(BTNode));
	if (root == NULL) {//当排序树为空的时候，直接给根赋值并返回
		root->data = n;
		root->left = root->right = NULL;
		return root;
	}
	while (p) {
		if (n == p->data)//要插入的值等于当前根的值时，不进行插入操作，直接返回
			return root;
		r = p;
		if (n < p->data)
			p = p->left;//插入的值小于当前根的值时，向当前树的左子树遍历
		else
			p = p->right;//插入的值大于当前根的值时，向当前树的右子树遍历
	}
	p = (PBTNode)malloc(sizeof(BTNode));//找到要插入的位置之后申请空间，赋值，插入
	p->data = n;
	p->left = p->right = NULL;
	if (n < r->data)
		r->left = p;//插入的值小于当前根的值时，插入左子树
	else
		r->right = p;//插入的值大于当前根的值时，插入右子树
	return root;
}
int Bi_Search(BiTreeLink root,int data) {//二分搜索
	PBTNode p = root;
	if (p == NULL)
		return 0;//不存在则返回0
	while (p) {
		if (p->data == data)
			return 1;
		else if (p->data < data)
			p = p->right;
		else
			p = p->left;
	}
	return 0;
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
	int datas[10] = { 40,20,13,56,84,46,32,47,20,65 }, i;
	PBTNode root = (PBTNode)malloc(sizeof(BTNode));
	root->data = datas[0];
	root->left = root->right = NULL;
	for (i = 1; i < 10; i++) {
		root = CreatBiTree(root, datas[i]);
	}
	printf("中序：\n");
	InOrder(root);
	printf("\n后序：\n");
	PostOrder(root);
	int s;
	printf("\n输入要查找的元素：\n");
	scanf("%d", &s);
	if (Bi_Search(root,s))
		printf("查找成功\n");
	else
		printf("查找失败\n");
	system("pause");
	return 0;
}
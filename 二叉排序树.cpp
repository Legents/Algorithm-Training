#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node *left;//左子树
	struct Node *right;//右子树
}BTNode, *PBTNode, *BiTreeLink;
BiTreeLink CreatBiTree(BiTreeLink root, int n) {
	PBTNode p = root, r = (PBTNode)malloc(sizeof(BTNode));
	if (root == NULL) {
		root->data = n;
		root->left = root->right = NULL;
		return root;
	}
	while (p) {
		if (n == p->data)
			return root;
		r = p;
		if (n < p->data)
			p = p->left;
		else
			p = p->right;
	}
	p = (PBTNode)malloc(sizeof(BTNode));
	p->data = n;
	p->left = p->right = NULL;
	if (n < r->data)
		r->left = p;
	else
		r->right = p;
	return root;
}
int Bi_Search(BiTreeLink root,int data) {
	PBTNode p = root;
	if (p->data > data)
		return Bi_Search(p->left, data);
	else if (p->data < data)
		return Bi_Search(p->right, data);
	else
		return 1;
	return 0;
}
int main() {
	int datas[10] = { 40,20,13,56,84,46,32,47,20,65 }, i;
	PBTNode root = (PBTNode)malloc(sizeof(BTNode));
	root->data = datas[0];
	root->left = root->right = NULL;
	for (i = 1; i < 10; i++) {
		root = CreatBiTree(root, datas[i]);
	}
	int s;
	scanf("%d", &s);
	if (Bi_Search)
		printf("查找成功\n");
	else
		printf("查找失败\n");
	system("pause");
	return 0;
}
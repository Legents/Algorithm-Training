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
void del(BiTreeLink root,int num) {
	PBTNode del_node = root;
	PBTNode par_of_del_node = NULL;
	PBTNode sub_node, par_of_sub_node;
	//寻找要删除的节点及其双亲节点
	while (del_node != NULL && num != del_node->data) {
		par_of_del_node = del_node;
		if (del_node->data > num)
			del_node = del_node->left;
		else
			del_node = del_node->right;
	}
	if (del_node == NULL)
	{
		printf("faild!\n");
		return;
	}
	//删除叶子节点
	if (del_node->left == NULL && del_node->right == NULL) {
		//删除的节点为根
		if (par_of_del_node == NULL)
			root = NULL;
		else if (par_of_del_node->left == del_node)
			par_of_del_node->left = NULL;
		else
			par_of_del_node->right = NULL;
		free(del_node);
	}
	//删除的节点有左子树
	else if (del_node->left != NULL && del_node->right == NULL) {
		//删除的节点为根节点
		if (par_of_del_node == NULL)
			root = del_node->left;
		else if (par_of_del_node->right == del_node)
			par_of_del_node->right = del_node->left;
		else
			par_of_del_node->left = del_node->left;
		free(del_node);
	}
	//删除的节点有右子树
	else if (del_node->left == NULL && del_node->right != NULL) {
		//删除的节点为根节点
		if (par_of_del_node == NULL)
			root = del_node->right;
		else if (par_of_del_node->right == del_node)
			par_of_del_node->right = del_node->right;
		else
			par_of_del_node->left = del_node->right;
		free(del_node);
	}
	//删除的节点既有左子树又有右子树
	else {
		par_of_sub_node = del_node;
		sub_node = del_node->left;
		//寻找替代节点和双亲节点
		while (sub_node->right != NULL) {
			par_of_sub_node = sub_node;
			sub_node = sub_node->right;
		}
		
		if (par_of_sub_node != del_node) {
			sub_node->right = del_node->right;
			sub_node->left = del_node->left;
			par_of_sub_node->right = NULL;
			//删除节点为根节点
			if (par_of_del_node == NULL) {
				root->data = sub_node->data;
			}
			else {
				if (par_of_del_node->left == del_node)
					par_of_del_node->left = sub_node;
				else
					par_of_del_node->right = sub_node;
			}
		}
		
		if (par_of_sub_node == del_node) {
			del_node->data = sub_node->data;
			if (par_of_sub_node->right == sub_node)
				del_node->right = NULL;
			else
				del_node->left = NULL;
		}
		else
			par_of_sub_node->right = NULL;
		free(sub_node);
	}
}
int main() {
	int datas[10] = { 2,1,3,4,5,6,7,8,9,10 }, i;
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
	/*printf("\n输入要查找的元素：\n");
	scanf("%d", &s);
	if (Bi_Search(root,s))
		printf("查找成功\n");
	else
		printf("查找失败\n");*/
	printf("输入要删除的节点:\n");
	scanf("%d", &s);
	del(root, s);
	printf("中序：\n");
	InOrder(root);
	printf("\n后序：\n");
	PostOrder(root);
	system("pause");
	return 0;
}
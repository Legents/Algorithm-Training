#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node *left;//������
	struct Node *right;//������
}BTNode, *PBTNode, *BiTreeLink;
BiTreeLink CreatBiTree(BiTreeLink root, int n) {
	PBTNode p = root, r = (PBTNode)malloc(sizeof(BTNode));
	if (root == NULL) {//��������Ϊ�յ�ʱ��ֱ�Ӹ�����ֵ������
		root->data = n;
		root->left = root->right = NULL;
		return root;
	}
	while (p) {
		if (n == p->data)//Ҫ�����ֵ���ڵ�ǰ����ֵʱ�������в��������ֱ�ӷ���
			return root;
		r = p;
		if (n < p->data)
			p = p->left;//�����ֵС�ڵ�ǰ����ֵʱ����ǰ��������������
		else
			p = p->right;//�����ֵ���ڵ�ǰ����ֵʱ����ǰ��������������
	}
	p = (PBTNode)malloc(sizeof(BTNode));//�ҵ�Ҫ�����λ��֮������ռ䣬��ֵ������
	p->data = n;
	p->left = p->right = NULL;
	if (n < r->data)
		r->left = p;//�����ֵС�ڵ�ǰ����ֵʱ������������
	else
		r->right = p;//�����ֵ���ڵ�ǰ����ֵʱ������������
	return root;
}
int Bi_Search(BiTreeLink root,int data) {//��������
	PBTNode p = root;
	if (p == NULL)
		return 0;//�������򷵻�0
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
void del(BiTreeLink root,int num) {
	PBTNode del_node = root;
	PBTNode par_of_del_node = NULL;
	PBTNode sub_node, par_of_sub_node;
	//Ѱ��Ҫɾ���Ľڵ㼰��˫�׽ڵ�
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
	//ɾ��Ҷ�ӽڵ�
	if (del_node->left == NULL && del_node->right == NULL) {
		//ɾ���Ľڵ�Ϊ��
		if (par_of_del_node == NULL)
			root = NULL;
		else if (par_of_del_node->left == del_node)
			par_of_del_node->left = NULL;
		else
			par_of_del_node->right = NULL;
		free(del_node);
	}
	//ɾ���Ľڵ���������
	else if (del_node->left != NULL && del_node->right == NULL) {
		//ɾ���Ľڵ�Ϊ���ڵ�
		if (par_of_del_node == NULL)
			root = del_node->left;
		else if (par_of_del_node->right == del_node)
			par_of_del_node->right = del_node->left;
		else
			par_of_del_node->left = del_node->left;
		free(del_node);
	}
	//ɾ���Ľڵ���������
	else if (del_node->left == NULL && del_node->right != NULL) {
		//ɾ���Ľڵ�Ϊ���ڵ�
		if (par_of_del_node == NULL)
			root = del_node->right;
		else if (par_of_del_node->right == del_node)
			par_of_del_node->right = del_node->right;
		else
			par_of_del_node->left = del_node->right;
		free(del_node);
	}
	//ɾ���Ľڵ��������������������
	else {
		par_of_sub_node = del_node;
		sub_node = del_node->left;
		//Ѱ������ڵ��˫�׽ڵ�
		while (sub_node->right != NULL) {
			par_of_sub_node = sub_node;
			sub_node = sub_node->right;
		}
		
		if (par_of_sub_node != del_node) {
			sub_node->right = del_node->right;
			sub_node->left = del_node->left;
			par_of_sub_node->right = NULL;
			//ɾ���ڵ�Ϊ���ڵ�
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
	printf("����\n");
	InOrder(root);
	printf("\n����\n");
	PostOrder(root);
	int s;
	/*printf("\n����Ҫ���ҵ�Ԫ�أ�\n");
	scanf("%d", &s);
	if (Bi_Search(root,s))
		printf("���ҳɹ�\n");
	else
		printf("����ʧ��\n");*/
	printf("����Ҫɾ���Ľڵ�:\n");
	scanf("%d", &s);
	del(root, s);
	printf("����\n");
	InOrder(root);
	printf("\n����\n");
	PostOrder(root);
	system("pause");
	return 0;
}
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
int main() {
	int datas[10] = { 40,20,13,56,84,46,32,47,20,65 }, i;
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
	printf("\n����Ҫ���ҵ�Ԫ�أ�\n");
	scanf("%d", &s);
	if (Bi_Search(root,s))
		printf("���ҳɹ�\n");
	else
		printf("����ʧ��\n");
	system("pause");
	return 0;
}
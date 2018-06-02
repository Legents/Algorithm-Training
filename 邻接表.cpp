#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXVEX 50
typedef struct arc {//�߱�ڵ�
	int adjvex;//�������
	struct arc *next;
}ArcNode, *PArcNode;
typedef struct vexNode{//����
	int data;//��������
	PArcNode h;
};
typedef struct {//�ڽӱ�
	vexNode list[20];//�����
	int e, v;//�ߣ�����
}VGraph, *Adjlist;
int compare(Adjlist G, int m,int n) {//�����жϴ˱��Ƿ��Ѿ�����
	PArcNode p = G->list[m].h;
	while (p) {
		if (p->adjvex == n)
			return 1;//������ �򷵻�1
		p = p->next;
	}
	return 0;
}
Adjlist Creat_G() {
	int m,n,i;
	Adjlist G=(Adjlist)malloc(sizeof(VGraph));
	printf("�����붥����Ŀ�ͱߵ���Ŀ��\n");
	scanf("%d%d", &G->v,&G->e);
	printf("��ֱ�����ÿ�������ֵ��\n");
	for (i = 0; i < G->v; i++) {//�����ĳ�ʼ��,�����ֵĬ������Ϊ��ŵ�ֵ
		G->list[i].data=i;
		G->list[i].h = NULL;
	}
	printf("������ߣ��Կո��������\n");
	for (i = 0; i < G->e; i++) {
		do {
			scanf("%d%d", &m, &n);
			if (m >= G->v || n >= G->v || m < 0 || n < 0) {//�ж�������ı��Ƿ����������㷶Χ֮��
				printf("������Χ�����������룺\n");
			}
			else {
				if (compare(G, m, n)) {//�ж�����ı��Ƿ��Ѿ�����
					printf("���Ѵ��ڣ����������룺\n");
				}
			}
		} while (m >= G->v || n >= G->v || m < 0 || n < 0 || compare(G, m, n));
		PArcNode p = (PArcNode)malloc(sizeof(ArcNode));
		p->adjvex = n;
		p->next = G->list[m].h;
		G->list[m].h = p;
	}
	return G;
}
void DFS_L(Adjlist G, int i, int visited[]) {
	printf("%3d", G->list[i].data);//������ʼ�߽ڵ�
	visited[i] = 1;
	PArcNode p = (PArcNode)malloc(sizeof(ArcNode));
	p = G->list[i].h;
	while (p) {
		if (!visited[p->adjvex])
			DFS_L(G, p->adjvex, visited);//�ݹ����η��ʱ߽ڵ���ڽӵ�
		p = p->next;
	}
}
void DFS(Adjlist G,int visited[]) {
	int i;
	for (i = 0; i < G->v; i++) {//���η���ÿ��δ���ʹ��ı߽ڵ�
		if (!(visited[i]))
			DFS_L(G, i,visited);
	}
}
int Front_Node(Adjlist G, int i) {//��ȡi��ǰһ���ڵ�
	if (i != -1) {
		PArcNode p = G->list[i].h;
		if (p != NULL)
			return p->adjvex;
	}
	else
		return -1;
}
int Next_Node(Adjlist G, int i, int j) {//��ȡi�ĺ�һ���ڵ�
	if (i!= -1) {
		PArcNode p = G->list[i].h;
		while (p != NULL && p->adjvex != j)
			p = p->next;
		if (p != NULL && p->next != NULL)
			return p->next->adjvex;
	}
	return -1;
}
void BFS(Adjlist G, int visited[]) {
	int Q[MAXVEX], front = 0, rear = 0;
	int i,m;
	for (i = 0; i < G->v; i++) {
		if (!visited[i]) {
			printf("%3d", G->list[i].data);
			visited[i] = 1;
			Q[rear++] = i;
			while (front < rear) {
				int j = Q[front++];
				for(m=Front_Node(G,j);m!=-1;m=Next_Node(G,j,m))
					if (!visited[m]) {
						printf("%3d", G->list[m].data);
						visited[m] = 1;
						Q[rear++] = m;
					}
			}
		}
	}
}
int main() {
	int visited[MAXVEX] = { 0 };
	Adjlist G = Creat_G();
	printf("����:\n");
	DFS(G, visited);
	printf("\n");
	int visited1[MAXVEX] = { 0 };
	printf("����:\n");
	BFS(G, visited1);
	printf("\n");
	system("pause");
	return 0;
}

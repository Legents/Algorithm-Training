#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXVEX 50
typedef struct arc {//边表节点
	int adjvex;//顶点序号
	struct arc *next;
}ArcNode, *PArcNode;
typedef struct vexNode{//顶点
	int data;//顶点内容
	PArcNode h;
};
typedef struct {//邻接表
	vexNode list[20];//顶点表
	int e, v;//边，顶点
}VGraph, *Adjlist;
Adjlist Creat_G() {
	int m,n,i;
	Adjlist G=(Adjlist)malloc(sizeof(VGraph));
	printf("请输入顶点数目和边的数目：\n");
	scanf("%d%d", &G->v,&G->e);
	printf("请分别输入每个顶点的值：\n");
	for (i = 0; i < G->v; i++) {//顶点表的初始化
		scanf("%d",&G->list[i].data);
		G->list[i].h = NULL;
	}
	printf("请输入边（以空格隔开）：\n");
	for (i = 0; i < G->e; i++) {
		scanf("%d%d", &m, &n);
		PArcNode p = (PArcNode)malloc(sizeof(ArcNode));
		p->adjvex = n;
		p->next = G->list[m].h;
		G->list[m].h = p;
	}
	return G;
}
void DFS_L(Adjlist G, int i, int visited[]) {
	printf("%3d", G->list[i].data);//访问起始边节点
	visited[i] = 1;
	PArcNode p = (PArcNode)malloc(sizeof(ArcNode));
	p = G->list[i].h;
	while (p) {
		if (!visited[p->adjvex])
			DFS_L(G, p->adjvex, visited);//递归依次访问边节点的邻接点
		p = p->next;
	}
}
void DFS(Adjlist G,int visited[]) {
	int i;
	for (i = 0; i < G->v; i++) {//依次访问每个未访问过的边节点
		if (!(visited[i]))
			DFS_L(G, i,visited);
	}
}
int Front_Node(Adjlist G, int i) {
	if (i != -1) {
		PArcNode p = G->list[i].h;
		if (p != NULL)
			return p->adjvex;
	}
	else
		return -1;
}
int Next_Node(Adjlist G, int i, int j) {
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
	printf("深搜:\n");
	DFS(G, visited);
	printf("\n");
	int visited1[MAXVEX] = { 0 };
	printf("广搜:\n");
	BFS(G, visited1);
	printf("\n");
	system("pause");
	return 0;
}

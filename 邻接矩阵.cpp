#include<stdio.h>
#include<stdlib.h>
#define MAX_V 50
#define MAX_E 50
typedef struct G {
	int e, v, vex[MAX_V];//vex[MAX_V]保存点的名称
	int arcs[MAX_V][MAX_V];//邻接矩阵
}Graph,*PGraph;
PGraph Creat_G() {
	PGraph G=(PGraph)malloc(sizeof(Graph));
	printf("请输入点和边的个数：\n");
	scanf("%d%d", &G->v, &G->e);
	int i, j;
	printf("请输入点：\n");
	for (i = 0; i < G->v; i++)//将每个点的名称默认置为序号
		G->vex[i] = i;
	for(i = 0; i < G->v; i++)
		for (j = 0; j < G->v; j++)
			G->arcs[i][j] = 0;//邻接矩阵的值置为默认0
	printf("请输入边：\n");
	for (i = 0; i < G->e; i++) {
		int m, n;
		do{
			scanf("%d%d", &m, &n);
			if(G->arcs[m][n]==1){//根据邻接矩阵判断点是否已经输入 若为1则重新输入
				printf("边重复，请重新输入：\n");
			}
			if (m >= G->v || n >= G->v || m < 0 || n < 0) {
				printf("超出范围，请重新输入：\n");
			}
		}while(G->arcs[m][n]==1|| m >= G->v || n >= G->v || m < 0 || n < 0);
		G->arcs[m][n] = 1;
	}
	return G;
}
void BFS(PGraph G, int k,int visited[]) {
	
	int quene[MAX_V], front = 0, rear = 0;//标记队列
	
		printf("%3d", G->vex[k]);
	quene[rear++] = k;//访问之后入队
	visited[k] = 1;
	while (front < rear) {
		int i = quene[front++],j;//访问队头元素的邻接点
		for (j = 0; j < G->v; j++) {
			if (G->arcs[i][j] == 1 && (!visited[j])) {
				printf("%3d", G->vex[j]);
				visited[j] = 1;
				quene[rear++]=j;
			}
		}
	}
}
void DFS(PGraph G, int k, int visited[]) {
	
	visited[k] = 1;
	int j;
	for (j = 0; j < G->v; j++) {
		if (G->arcs[k][j] == 1 && (!visited[j])) {
			DFS(G, j, visited);
		}
	}
	printf("%3d", k);
}
void print(PGraph G) {//输出邻接矩阵
	int i, j;
	printf("邻接矩阵的输出：\n");
	printf("    ");
	for (i = 0; i < G->v; i++)
		printf("%3d", G->vex[i]);
	printf("\n");
	for (i = 0; i < G->v; i++) {
		printf("%3d|", G->vex[i]);
		for (j = 0; j < G->v; j++)
			printf("%3d", G->arcs[i][j]);
		printf("\n");
	}
}
int main() {
	PGraph G = Creat_G();
	print(G);
	int i;
	int visited[MAX_V] = { 0 };
	printf("广搜\n");
	for (i = 0; i < G->v; i++) {//调用一次只能输出一个最大连通分量  要完整的输出一个非连通图则要从每一个点出发对搜索函数进行调用
		if (visited[i])
			continue;
		BFS(G, i,visited);
	}
	printf("\n深搜\n");
	int visited1[MAX_V] = { 0 };
	for (i = 0; i < G->v; i++) {
		if (visited1[i])
			continue;
		DFS(G, i,visited1);
	}
	printf("\n");
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#define MAX_V 50
#define MAX_E 50
typedef struct G {
	int e, v, vex[MAX_V];
	int arcs[MAX_V][MAX_V];
}Graph,*PGraph;
PGraph Creat_G() {
	PGraph G=(PGraph)malloc(sizeof(Graph));
	printf("请输入点和边的个数：\n");
	scanf("%d%d", &G->v, &G->e);
	int i, j;
	printf("请输入点：\n");
	for (i = 0; i < G->v; i++)
		G->vex[i] = i;
	for(i = 0; i < G->v; i++)
		for (j = 0; j < G->v; j++)
			G->arcs[i][j] = 0;
	printf("请输入边：\n");
	for (i = 0; i < G->e; i++) {
		int m, n;
		scanf("%d%d", &m, &n);
		G->arcs[m][n] = 1;
	}
	return G;
}
void BFS(PGraph G, int k,int visited[]) {
	
	int quene[MAX_V], front = 0, rear = 0;
	
		printf("%3d", G->vex[k]);
	quene[rear++] = k;
	visited[k] = 1;
	while (front < rear) {
		int i = quene[front++],j;
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
void print(PGraph G) {
	int i, j;
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
	for (i = 0; i < G->v; i++) {
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
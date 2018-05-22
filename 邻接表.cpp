#include<stdio.h>
#define MAXVEX 50
typedef struct arc {//边表节点
	int adjvex;//顶点序号
	struct arc *next;
}ArcNode, *PArcNode;
typedef struct vexNode{//顶点
	char ch;//顶点内容
	PArcNode h;
};
typedef struct {//邻接表
	vexNode list[MAXVEX];//顶点表
	int e, v;//边，顶点
}VGraph, *Adjlist;

#include<stdio.h>
#define MAXVEX 50
typedef struct arc {//�߱�ڵ�
	int adjvex;//�������
	struct arc *next;
}ArcNode, *PArcNode;
typedef struct vexNode{//����
	char ch;//��������
	PArcNode h;
};
typedef struct {//�ڽӱ�
	vexNode list[MAXVEX];//�����
	int e, v;//�ߣ�����
}VGraph, *Adjlist;

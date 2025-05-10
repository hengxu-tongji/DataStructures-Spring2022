#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int visited[10005];
typedef struct ArcNode {
	int adjvex;  //该弧所指向的顶点的位置
	struct ArcNode* nextarc;//指向下一条弧的指针
	int info;
}ArcNode;  //边结点类型
typedef struct VNode {
	int data;   //顶点信息
	ArcNode* firstarc; //指向第一条依附该顶点的指针
}VNode, AdjList[10005];
typedef struct {
	AdjList vertices;  //邻接表
	int vexnum, arcnum;
}ALGraph;
typedef struct {
	int* base;
	int   front;
	int   rear;
}SqQueue;
int InitQueue(SqQueue& Q, int n) {
	Q.base = (int*)malloc((n + 1) * sizeof(int));
	if (!Q.base) return -1;
	Q.front = Q.rear = 0;
	return 0;
}
void CreateALGraph_adjlist(ALGraph& G)
{
	int i, j, k, w;  int v1, v2;
	ArcNode* p, * q;
	cin >> G.vexnum >> G.arcnum;
	for (i = 0;i < G.vexnum;i++)
	{
		G.vertices[i].data = i;
		G.vertices[i].firstarc = NULL;
	}
	for (k = 0;k < G.arcnum;k++)
	{
		cin >> v1 >> v2;
		i = v1;
		j = v2;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = 0;
		p->nextarc = NULL;
		q = G.vertices[i].firstarc;
		if (q == NULL) G.vertices[i].firstarc = p;
		else {
			while (q->nextarc != NULL) q = q->nextarc;
			q->nextarc = p;
		}
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->info = 0;
		p->nextarc = NULL;
		q = G.vertices[j].firstarc;
		if (q == NULL) G.vertices[j].firstarc = p;
		else {
			while (q->nextarc != NULL) q = q->nextarc;
			q->nextarc = p;
		}
	}
	return;
}
void BFS(ALGraph G, int v)
{
	ArcNode* p;	SqQueue Q;
	InitQueue(Q, G.vexnum);
	cout << G.vertices[v].data;
	visited[v] = 1;
	Q.base[Q.rear] = v;
	Q.rear = (Q.rear + 1) % (G.vexnum + 1);
	while (Q.front != Q.rear)
	{
		v = Q.base[Q.front];
		Q.front = (Q.front + 1) % (G.vexnum + 1);
		p = G.vertices[v].firstarc;
		while (p)
		{
			if (!visited[p->adjvex])
			{
				cout << ' ' << G.vertices[p->adjvex].data;
				visited[p->adjvex] = 1;
				Q.base[Q.rear] = p->adjvex;
				Q.rear = (Q.rear + 1) % (G.vexnum + 1);
			}
			p = p->nextarc;
		}
	}
}
void BFSTraverse(ALGraph G) {
	int v;
	for (v = 0;v < G.vexnum;++v)
		visited[v] = 0;
	for (v = 0;v < G.vexnum;++v)
		if (!visited[v]) {
			cout << '{';
			BFS(G, v);
			cout << '}';
		}
}
void DFS(ALGraph G, int v, int check)
{
	ArcNode* p;
	if (check == 0) cout << ' ' << G.vertices[v].data;
	visited[v] = 1;
	p = G.vertices[v].firstarc;
	while (p)
	{
		if (!visited[p->adjvex]) DFS(G, p->adjvex, 0);
		p = p->nextarc;
	}
}
void DFSTraverse(ALGraph G) {
	int v;
	for (v = 0;v < G.vexnum;++v)
		visited[v] = 0;
	for (v = 0;v < G.vexnum;++v)
		if (!visited[v]) {
			cout << '{' << G.vertices[v].data;
			DFS(G, v, 1);
			cout << '}';
		}
}
int main() {
	ALGraph G;
	CreateALGraph_adjlist(G);
	DFSTraverse(G);
	cout << endl;
	BFSTraverse(G);
	return 0;
}
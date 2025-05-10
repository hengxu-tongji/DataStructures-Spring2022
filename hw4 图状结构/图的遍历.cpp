#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
#define MAX_VERTEX_NUM 200//最大顶点数

struct ArcNode//顶点节点
{
	int adjvex;//下标（位置）
	ArcNode* nextarc;
};

typedef struct VNode//弧节点
{
	int data;//头结点
	ArcNode* firstarc;//指向第一条弧的指针
} AdjList[MAX_VERTEX_NUM];

struct ALGraph//邻接表构造
{
	AdjList vertices;//邻接表
	int vexnum, arcnum;//顶点数和弧数
};

int LocateVex_(ALGraph G, int u)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (u == G.vertices[i].data)
			return i;
	}
	return 0;
}

void CreateALGraph_adjlist(ALGraph& G)//尾插法建立
{
	ArcNode* p;
	int x, y;
	int v1, v2;
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++)
	{
		G.vertices[i].data = i;
		G.vertices[i].firstarc = NULL;
	}
	for (int i = 0; i < G.arcnum; i++)
	{
		cin >> v1 >> v2;
		x = LocateVex_(G, v1);
		y = LocateVex_(G, v2);
		ArcNode* t;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = y;
		p->nextarc = NULL;
		t = G.vertices[x].firstarc;
		if (t == NULL)//第x个顶点的边表结点为空
		{
			G.vertices[x].firstarc = p;//实现两点相连
		}
		else
		{
			while (t->nextarc != NULL)
			{
				t = t->nextarc;
			}
			t->nextarc = p;
		}
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = x;
		p->nextarc = NULL; G.vertices[y].firstarc;
		t = G.vertices[y].firstarc;
		if (t == NULL)//第x个顶点的边表结点为空
		{
			G.vertices[y].firstarc = p;//实现两点相连
		}
		else
		{
			while (t->nextarc != NULL)
			{
				t = t->nextarc;
			}
			t->nextarc = p;
		}
	}
}

int visited[MAX_VERTEX_NUM];//辅助数组，判断是否访问

void DFS(ALGraph G, int i)//深度优先算法
{
	ArcNode* p;
	p = G.vertices[i].firstarc;
	if (!visited[i])
	{
		cout << " ";
		cout << i;
	}
	visited[i] = 1;//已被遍历
	while (p)
	{
		if (!visited[p->adjvex])//未被遍历
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

void DFSTraverse(ALGraph G)
{
	for (int i = 0; i < G.vexnum; i++)//辅助数组初始化，都未被访问过
		visited[i] = 0;
	for (int i = 0; i < G.vexnum; i++)
		if (!visited[i])
		{
			cout << "{";
			visited[i] = 1;
			cout << i;
			DFS(G, i);
			cout << "}";
		}
	cout << endl;
}

#define MAXQSIZE 1000

typedef struct {
	int* base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue& Q)
{
	Q.base = (int*)malloc(MAXQSIZE * sizeof(int));
	if (!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return 1;
}

int c;

void BFS(ALGraph G, int v)
{
	ArcNode* p;
	SqQueue Q;
	InitQueue(Q);
	cout << G.vertices[v].data;
	visited[v] = 1;
	Q.base[Q.rear] = v;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	p = G.vertices[v].firstarc;
	while (Q.front != Q.rear)
	{
		v = Q.base[Q.front];
		Q.front = (Q.front + 1) % MAXQSIZE;
		p = G.vertices[v].firstarc;
	}
	while (p)
	{
		if (!visited[p->adjvex])
		{
			cout << " " << G.vertices[p->adjvex].data;
			visited[p->adjvex] = 1;
			Q.base[Q.rear] = p->adjvex;
			Q.rear = (Q.rear + 1) % MAXQSIZE;
		}
		p = p->nextarc;
	}
}

void BFSTraverse(ALGraph G)
{
	for (int v = 0; v < G.vexnum; ++v)
		visited[v] = 0;
	for (int v = 0; v < G.vexnum; ++v)
		if (!visited[v])
		{
			cout << "{";
			c = 0;
			BFS(G, v);
			cout << "}";
		}
}

int main()
{
	ALGraph G;
	CreateALGraph_adjlist(G);
	DFSTraverse(G);
	BFSTraverse(G);
}

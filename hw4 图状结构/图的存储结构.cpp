#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define MAX_VERTEX_NUM 200//��󶥵���
typedef int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ�������
struct MGraph
{
	int vexnum, arcnum;//ͼ�Ķ������ͱ�/����
	char vexs[MAX_VERTEX_NUM];//�����
	char v1[MAX_VERTEX_NUM], v2[MAX_VERTEX_NUM];
	AdjMatrix arcs;//�ڽӾ���
};
int x, y;

int LocateVex(MGraph G, char u)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (u == G.vexs[i])
			return i;
	}
	return 0;
}

void CreateMGraph(MGraph& G, int species)//�ڽӾ���Ľ���
{
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++)
		cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;
	}
	for (int i = 0; i < G.arcnum; i++)
	{
		int w = 1;
		cin >> G.v1[i] >> G.v2[i];
		if (species % 2 == 0)
			cin >> w;
		x = LocateVex(G, G.v1[i]);
		y = LocateVex(G, G.v2[i]);
		G.arcs[x][y] = w;
		if (species >= 3)
			G.arcs[y][x] = w;
	}
}

void PrintMGraph(MGraph G)
{
	for (int i = 0; i < G.vexnum; i++)
		cout << G.vexs[i] << " ";
	cout << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
			printf("%4d", G.arcs[i][j]);
		cout << endl;
	}
}

struct ArcNode//����ڵ�
{
	int adjvex;//�±꣨λ�ã�
	int info;//�洢������
	ArcNode* nextarc;
};

typedef struct VNode//���ڵ�
{
	char data;//ͷ���
	ArcNode* firstarc;//ָ���һ������ָ��
} AdjList[MAX_VERTEX_NUM];

struct ALGraph
{
	AdjList vertices;//�ڽӱ�
	int vexnum, arcnum;//�������ͻ���
};

int LocateVex_(ALGraph G, char u)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (u == G.vertices[i].data)
			return i;
	}
	return 0;
}

void CreateALGraph_adjlist(ALGraph& G, int species, MGraph G0)
{
	ArcNode* p;
	G.vexnum = G0.vexnum;
	G.arcnum = G0.arcnum;
	for (int i = 0; i < G.vexnum; i++)
	{
		G.vertices[i].data = G0.vexs[i];
		G.vertices[i].firstarc = NULL;
	}
	for (int i = 0; i < G.arcnum; i++)
	{
		x = LocateVex_(G, G0.v1[i]);
		y = LocateVex_(G, G0.v2[i]);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = y;
		p->info = G0.arcs[x][y];
		p->nextarc = G.vertices[x].firstarc;
		G.vertices[x].firstarc = p;
		if (species >= 3)
		{
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = x;
			p->info = G0.arcs[x][y];
			p->nextarc = G.vertices[y].firstarc;
			G.vertices[y].firstarc = p;
		}
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		cout << G.vertices[i].data << "-->";
		ArcNode* t = G.vertices[i].firstarc;
		while (t)
		{
			if (species % 2 == 1)
				cout << t->adjvex;
			else
				cout << t->adjvex << "," << t->info;
			t = t->nextarc;
			if (t)
				cout << " ";
		}
		cout << endl;
	}
}

int main()
{
	int species;
	MGraph M;
	ALGraph G;
	cin >> species;
	CreateMGraph(M, species);
	PrintMGraph(M);
	CreateALGraph_adjlist(G, species, M);
}
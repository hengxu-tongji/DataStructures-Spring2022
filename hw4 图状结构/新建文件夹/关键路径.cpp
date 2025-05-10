#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct ArcNode {
	int adjvex;  //该弧所指向的顶点的位置
	struct ArcNode* nextarc;//指向下一条弧的指针
	int info;
}ArcNode;  //边结点类型
typedef struct VNode {
	int data;   //顶点信息
	int indegree;
	ArcNode* firstarc; //指向第一条依附该顶点的指针
}VNode, AdjList[100000];
typedef struct {
	AdjList vertices;  //邻接表
	int vexnum, arcnum;
	int kind;
}ALGraph;
typedef struct {
	int* base;
	int* top;
	int stacksize;
}SqStack;
int InitStack(SqStack& S, int n) {
	S.base = (int*)malloc(n * sizeof(int));
	if (!S.base) return -1;
	S.top = S.base;
	S.stacksize = n;
	return 0;
}
int push(SqStack& S, int e)
{
	if (S.top - S.base >= S.stacksize) {
		cout << "Stack is Full" << endl;
		return -1;
	}
	*S.top++ = e;
	return 0;
}int pop(SqStack& S, int& e)
{
	if (S.top == S.base) {
		cout << "Stack is Empty" << endl;
		return -1;
	}
	e = *--S.top;
	return 0;
}
int CreateGraph(ALGraph& G) {
	int i, j, k, w;    int v1, v2, count = 0;
	ArcNode* p;
	cin >> G.vexnum >> G.arcnum;
	for (k = 0;k < G.vexnum;k++) {
		G.vertices[k].data = k + 1;
		G.vertices[k].indegree = 0;
		G.vertices[k].firstarc = NULL;
	}
	for (k = 0;k < G.arcnum;k++) {
		cin >> v1 >> v2 >> w;
		i = v1 - 1;
		j = v2 - 1;
		for (p = G.vertices[i].firstarc;p;p = p->nextarc)
			if (j == p->adjvex) break;
		if (p != NULL) {
			count++;
			p->info = max(w, p->info);
		}
		else {
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = j;
			p->info = w;
			G.vertices[j].indegree++;
			p->nextarc = G.vertices[i].firstarc;
			G.vertices[i].firstarc = p;
		}
	}
	G.arcnum = G.arcnum - count;
	return 0;
}
int CriticalPath(ALGraph G, SqStack& T) {
	int count = 0, ve[100000], vl[100000], i, j; ArcNode* p;
	int ee, el, max;
	SqStack S;
	InitStack(S, G.vexnum);
	for (i = 0;i < G.vexnum;i++)
		if (!G.vertices[i].indegree)
			push(S, i);
	for (i = 0;i < G.vexnum;i++) ve[i] = 0;
	InitStack(T, G.vexnum);
	while (S.top != S.base) {
		pop(S, j); push(T, j); ++count;
		for (p = G.vertices[j].firstarc;p;p = p->nextarc) {
			i = p->adjvex;
			if (--G.vertices[i].indegree == 0) push(S, i);
			if (ve[j] + (p->info) > ve[i]) ve[i] = ve[j] + (p->info);
		}
	}
	if (count < G.vexnum) {
		cout << 0 << endl;
		return -1;
	}
	for (max = 0, i = 0;i < G.vexnum;i++)
		if (max < ve[i]) max = ve[i];
	for (i = 0;i < G.vexnum;i++) vl[i] = max;
	while (T.top != T.base)
		for (pop(T, j), p = G.vertices[j].firstarc;p;p = p->nextarc) {
			i = p->adjvex;
			if (vl[i] - (p->info) < vl[j]) vl[j] = vl[i] - (p->info);
		}
	cout << max << endl;
	for (j = 0;j < G.vexnum;++j)
		for (p = G.vertices[j].firstarc;p;p = p->nextarc) {
			i = p->adjvex;
			ee = ve[j];
			el = vl[i] - (p->info);
			if (ee == el) cout << G.vertices[j].data << "->" << G.vertices[i].data << endl;
		}
	return 0;
}
int main() {
	ALGraph G;
	SqStack T;
	CreateGraph(G);
	InitStack(T, G.vexnum);
	CriticalPath(G, T);
	return 0;
}
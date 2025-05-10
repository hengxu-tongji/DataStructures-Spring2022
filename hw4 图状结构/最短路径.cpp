#include<iostream>
#include<queue>
using namespace std;
const int inf = 1000000;
struct node {
	int next, to, dis;
}edge[inf];
int vis[inf], head[inf], num = 0, dis[inf];
int n, m, s;
void addedge(int a, int b, int c)
{
	edge[++num].next = head[a];
	edge[num].to = b;
	edge[num].dis = c;
	head[a] = num;
	edge[++num].next = head[b];
	edge[num].to = a;
	edge[num].dis = c;
	head[b] = num;
}
void spfa()
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = inf;
		vis[i] = 0;
	}
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	dis[s] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (dis[v] > dis[u] + edge[i].dis)
			{
				dis[v] = dis[u] + edge[i].dis;
				if (vis[v] == 0)
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	int a, b, c;
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		addedge(a, b, c);
	}
	spfa();
	for (int i = 1; i <= n; i++)
		if (dis[i] == inf)
			cout << "2147483647" << " ";
		else
			cout << dis[i] << " ";
	return 0;
}
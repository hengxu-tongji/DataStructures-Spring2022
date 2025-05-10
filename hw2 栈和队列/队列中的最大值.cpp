#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
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
int EnQueue(SqQueue& Q, SqQueue& D, int e, int n) {
	if ((Q.rear + 1) % (n + 1) == Q.front) {
		cout << "Queue is Full" << endl;
		return -1;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % (n + 1);
	if (D.rear != D.front) {
		while (D.base[(D.rear - 1) % (n + 1)] < e) {
			D.rear = (D.rear - 1) % (n + 1);
			if (D.rear == D.front) break;
		}
	}
	D.base[D.rear] = e;
	D.rear = (D.rear + 1) % (n + 1);
	return 0;
}
int DeQueue(SqQueue& Q, SqQueue& D, int& e, int n) {
	if (Q.rear == Q.front) {
		cout << "Queue is Empty" << endl;
		return -1;
	}
	e = Q.base[Q.front];
	cout << e << endl;
	Q.front = (Q.front + 1) % (n + 1);
	if (e == D.base[D.front]) D.front = (D.front + 1) % (n + 1);
	return 0;
}
int main() {
	SqQueue Q, D;
	int n, e;
	char c[8];
	cin >> n;
	InitQueue(Q, n); InitQueue(D, n);
	for (cin >> c;strcmp(c, "quit") != 0;cin >> c) {//ÊäÈëº¯ÊýÃû
		if (strcmp(c, "dequeue") == 0)
			DeQueue(Q, D, e, n);
		else if (strcmp(c, "enqueue") == 0) {
			cin >> e;
			EnQueue(Q, D, e, n);
		}
		else if (strcmp(c, "max") == 0) {
			if (D.front == D.rear) cout << "Queue is Empty" << endl;
			else cout << D.base[D.front] << endl;
		}
	}
	for (cout << Q.base[Q.front];(Q.front + 1) % (n + 1) != Q.rear;Q.front = (Q.front + 1) % (n + 1))
		cout << ' ' << Q.base[(Q.front + 1) % (n + 1)];
	cout << endl;
	return 0;
}
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define STACK_INIT_SIZE 100


typedef struct {
	char* base;
	char* top;
	int stacksize;
}SqStack;


int InitStack(SqStack& S) {
	S.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!S.base) return -1;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 0;
}


int Push(SqStack& S, char e)
{
	if (S.top - S.base >= S.stacksize) return -1;
	*S.top++ = e;
	return 0;
}

int Pop(SqStack& S)
{
	if (S.top == S.base) return -1;
	--S.top;
	return 0;
}


int judge(char c[], char d[]) {
	SqStack S;
	int i, j;
	InitStack(S);
	for (i = 0, j = 0;c[i] != '\0';i++) {
		Push(S, c[i]);
		while (*(S.top - 1) == d[j]) {
			Pop(S);
			j++;
			if (S.top == S.base) break;
		}
	}
	if (S.top == S.base) return 0;
	else return -1;
}


int main()
{
	char c[100], d[100];
	cin >> c;
	while ((cin >> d)) {
		if (judge(c, d)) cout << "no" << endl;
		else cout << "yes" << endl;
	}
	return 0;
}
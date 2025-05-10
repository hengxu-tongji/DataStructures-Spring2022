#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;
typedef struct{
	BiTree *base;
	BiTree *top;
	int stacksize;
}SqStack;
int InitStack(SqStack &S) {
   S.base=(BiTree*)malloc(83*sizeof(BiTNode));
    if (!S.base) return -1;
    S.top=S.base;
    S.stacksize =83;
    return 0;
}
int Push(SqStack &S,BiTree e)
{
    if (S.top-S.base>=S.stacksize)
      return -1;
    *S.top++=e;
    return 0;
}
int Pop(SqStack &S,BiTree &e){
    if(S.top==S.base)
        return -1;
    e=*--S.top;
    return 0;
}
void PostOrderTraverse(BiTree T){
	if(T){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);}
}
int main(){
	BiTree T,p,q;char c[5],e;SqStack S;
	int n,i,flag=-1;
	InitStack(S);
	cin>>n;
	for(cin>>c,i=0;i<n;cin>>c){
		if(strcmp(c,"push")==0){
			cin>>e;
			p=(BiTree)malloc(sizeof(BiTNode));
			p->data=e;p->lchild=p->rchild=NULL;
			Push(S,p);
			if(flag==-1) T=p;
			else if(flag==1){q=*(S.top-2);q->lchild=p;}
			else if(flag==0) q->rchild=p;
			flag=1;}
		else if(strcmp(c,"pop")==0){
			Pop(S,q);
			i++;
			flag=0;}}
	PostOrderTraverse(T);
	return 0;
}
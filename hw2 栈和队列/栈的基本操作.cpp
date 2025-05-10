#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;
int InitStack(SqStack &S,int n) {
   S.base = (int *)malloc(n*sizeof(int));
	if (!S.base) return -1;
	S.top=S.base;
	S.stacksize = n;
	return 0;
}
int Push(SqStack &S,int e)
{
	if (S.top-S.base>=S.stacksize){
	  cout<<"Stack is Full"<<endl;
	  return -1;}
    *S.top++=e;
    return 0;
}int Pop(SqStack &S,int &e)
{
	if(S.top==S.base){ 
		cout<<"Stack is Empty"<<endl;
		return -1;}
	e=*--S.top;
	cout<<e<<endl;
	return 0;
}
int Allpop(SqStack &S){
	if(S.top>S.base){
		--S.top;
		cout<<*S.top;
	while(S.top!=S.base){
		--S.top;
		cout<<' '<<*S.top;}}
	return 0;
}
int main(){
	SqStack S;
	int n,e;
	char c[5];
	cin>>n;
	InitStack(S,n);
	for(cin>>c;strcmp(c,"end")!=0;cin>>c){//ÊäÈëº¯ÊýÃû
		if(strcmp(c,"pop")==0) Pop(S,e);
		else if(strcmp(c,"push")==0){
			cin>>e;Push(S,e);}
		else if(strcmp(c,"quit")==0) {
			Allpop(S);
		    system("pause");
			return 0;}
		else return -1;}
}
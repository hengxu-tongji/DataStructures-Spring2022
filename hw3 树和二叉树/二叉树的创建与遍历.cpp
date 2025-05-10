#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
using namespace std;
typedef struct BiTNode {
	char data;
	int LTag = 0;
	int RTag = 0;
	struct BiTNode* lchild = nullptr;
	struct BiTNode* rchild = nullptr;
	struct BiTNode* parent = nullptr;
}BiTNode, * BiTree;


BiTree pre = new BiTNode;
BiTree NewT = new BiTNode;
BiTree parent = NULL;

//����������
int CreateBiTree(BiTree &T,BiTree P){
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#') T = NULL;
	else{
		T = new BiTNode;
		T->data = ch;
		T->parent = P;
		CreateBiTree(T->lchild, T);
		CreateBiTree(T->rchild, T);
	}
	return 0;
}

//������
void Copy(BiTree T, BiTree& NewT)
{
	if (T == NULL)
	{
		NewT = NULL;
		return;
	}
	else
	{
		NewT = new BiTNode;
		NewT->data = T->data;
		NewT->parent = T->parent;
		Copy(T->lchild, NewT->lchild);
		Copy(T->rchild, NewT->rchild);
	}
}


//�������
void PreOrderTraverse(BiTree T){
	if (T){
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);}
}

//�������
void InOrderTraverse(BiTree T){
	if (T){
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);}
}

//�������
void PostOrderTraverse(BiTree T){
	if (T){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);}
}

//ͳ��Ҷ�ӽ�����
int Leaf(BiTree T)
{
	int count;
	if (T == NULL)
		count = 0;
	else if (T->lchild == NULL && T->rchild == NULL)
		count = 1;
	else
		count = Leaf(T->lchild) + Leaf(T->rchild);
	return count;
}

//�Խ��TΪ������������������
void PreThreading(BiTree& T)
{
	if(T)//T�ǿ�
	{
		if (!T->lchild)//������Ϊ��
		{
			T->LTag = 1;
			T->lchild = pre;
		}
		else
		{
			T->LTag = 0;
		}
		if (!pre->rchild)
		{
			pre->RTag = 1;
			pre->rchild = T;
		}
		else
		{
			T->RTag = 0;
		}
		pre = T;
		if (T->LTag == 0)
		{
			PreThreading(T->lchild);//����������
		}
		if (T->RTag == 0)
		{
			PreThreading(T->rchild);//����������
		}
	}
}

//��ͷ�ڵ�Ķ���������������
void PreOrderThreading(BiTree& Thrt, BiTree T)
{
	pre = new BiTNode;
	Thrt = new BiTNode;
	NewT = new BiTNode;
	Copy(T, NewT);
	Thrt->LTag = 0;
	Thrt->RTag = 1;
	Thrt->rchild = Thrt;
	if (!NewT)
	{
		Thrt->lchild = Thrt;
	}
	else
	{
		Thrt->lchild = NewT;
		pre = Thrt;
		PreThreading(NewT);
		pre->rchild = Thrt;
		pre->RTag = 1;
		Thrt->rchild = pre;
	}
}

//������������������
void PreTraverse_Thr(BiTree T)
{
	BiTree p = T->lchild;
	while (p != T)
	{
		cout << p->data;
		if (p->LTag == 0)
		{
			p = p->lchild;
		}
		else
		{
			p = p->rchild;
		}
	}
	cout << endl;
}

//�Խ��TΪ������������������
void InThreading(BiTree& T)
{
	if (T)//T�ǿ�
	{
		InThreading(T->lchild);//����������
		if (!T->lchild)//������Ϊ��
		{
			T->LTag = 1;
			T->lchild = pre;
		}
		else
		{
			T->LTag = 0;
		}
		if (!pre->rchild)
		{
			pre->RTag = 1;
			pre->rchild = T;
		}
		else
		{
			T->RTag = 0;
		}
		pre = T;
		InThreading(T->rchild);
	}
}

//��ͷ�ڵ�Ķ���������������
void InOrderThreading(BiTree& Thrt, BiTree T)
{
	pre = new BiTNode;
	Thrt = new BiTNode;
	NewT = new BiTNode;
	Copy(T, NewT);
	Thrt->LTag = 0;
	Thrt->RTag = 1;
	Thrt->rchild = Thrt;
	if (!NewT)
	{
		Thrt->lchild = Thrt;
	}
	else
	{
		Thrt->lchild = NewT;
		pre = Thrt;
		InThreading(NewT);
		pre->rchild = Thrt;
		pre->RTag = 1;
		Thrt->rchild = pre;
	}
}

//������������������
void InTraverse_Thr(BiTree T)
{
	BiTree p = T->lchild;//
	while (p != T)
	{
		while (p->LTag == 0)
		{
			p = p->lchild;
		}
		cout << p->data;
		while (p->RTag == 1 && p->rchild != T)
		{
			p = p->rchild;
			cout << p->data;
		}
		p = p->rchild;
	}
	cout << endl;
}

//�Խ��TΪ������������������
void PosThreading(BiTree& T)
{
	if (T)//T�ǿ�
	{
		PosThreading(T->lchild);//����������
		PosThreading(T->rchild);//����������
		if (!T->lchild)//������Ϊ��
		{
			T->LTag = 1;
			T->lchild = pre;
		}
		else
		{
			T->LTag = 0;
		}
		if (!pre->rchild)
		{
			pre->RTag = 1;
			pre->rchild = T;
		}
		else
		{
			T->RTag = 0;
		}
		pre = T;
	}
}

//��ͷ�ڵ�Ķ���������������
void PosOrderThreading(BiTree& Thrt, BiTree T)
{
	pre = new BiTNode;
	Thrt = new BiTNode;
	Thrt->LTag = 0;
	Thrt->RTag = 1;
	Thrt->rchild = T;
	if (!T)
	{
		Thrt->lchild = Thrt;
	}
	else
	{
		Thrt->lchild = T;
		pre = Thrt;
		PosThreading(T);
	}
}

//������������������
void PosTraverse_Thr(BiTree T)
{
	BiTree root = T->lchild;//��ʼ�ڵ�
	BiTree prev = nullptr;//��¼��һ���ڵ�
	while (root)
	{
		if (root->lchild == root->rchild)//���˫��û������������������
		{
			root = root->rchild;
		}
		while (root->LTag == 0 && root->lchild != prev)//�ҵ�����ߵĽڵ�
		{
			root = root->lchild;
		}
		while (root->RTag == 1)//����������ڵ�ĺ��
		{
			cout << root->data;
			prev = root;//��¼��һ���ڵ�
			root = root->rchild;
		}
		if (root == T->lchild)//�ж��ǲ��Ǹ��ڵ�
		{
			cout << root->data;
			return;
		}
		while (root->rchild == prev)//���Ǹ��ڵ㣬���ʵ�ǰ�ڵ��˫�׽ڵ�
		{
			cout << root->data;
			prev = root;
			root = root->parent;
			if (root == nullptr)//���������ڵ㣬�˳�
			{
				return;
			}
		}
		if (root->RTag == 0)//����������
		{
			root = root->rchild;
		}
	}
	cout << endl;
}

//��ӡ������
void PrintBiTree(BiTree T,int n){
	int i; char ch=' ';
	if(T){
		PrintBiTree(T->rchild,n+1);
		for (i=1;i<=n;++i) {printf("%5c",ch);}
		printf("%c\n", T->data);
		PrintBiTree(T->lchild,n+1);}
}


int main(){
	BiTree T;
	BiTree P = nullptr;
	BiTree Thrt;
	CreateBiTree(T,P);//����������
	PreOrderTraverse(T);//�������
	cout<<endl;
	InOrderTraverse(T);//�������
	cout<<endl;
	PostOrderTraverse(T);//�������
	cout<<endl;
	cout << Leaf(T) << endl;//Ҷ�ӽڵ����
	PreOrderThreading(Thrt, T);
	PreTraverse_Thr(Thrt);
	InOrderThreading(Thrt, T);
	InTraverse_Thr(Thrt);
	PosOrderThreading(Thrt, T);
	PosTraverse_Thr(Thrt);
	return 0;
}
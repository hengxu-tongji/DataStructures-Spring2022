#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
using namespace std;
 
struct Polynominal {
    float coef;    //系数
    int expn;    //指数
    Polynominal* next;
};//多项式存储

struct LinkList {
    Polynominal* data;
    LinkList* next;
}; //链表



void Create(LinkList* p,int n)
{
    LinkList* head = new LinkList;
    LinkList* p = head;
    for (int i = 0;i < n;++i) {
        LinkList* q = new LinkList;
        cin >> q->data->coef >> q->data->expn;
        p->next = q;
        p = p->next;
    }
}//输入多项式




void Add(LinkList* px, LinkList* qx，LinkList* rx)
{

}//多项式相加并将结果存在rx中




void Multiply(LinkList* px, LinkList* qx)
{

}//多项式相乘并将结果存在rx中



void Output(LinkList* p);
{

}




int main()
{
    LinkList pa, pb, pc;
    int m, n, i;
    cin >> m;
    Create(&pa, m);//输入第一个多项式
    cin >> n;
    Create(&pb, n);//输入第二个多项式
    Create(&pc, 0);//初始化pc
    cin >> i;
    switch (i) {
    case 0:
        Add(&pa, &pb,&pc);
        Output(&pc);//输入0时输出相加的多项式
    case 1:
        Multiply(&pa, &pb, &pc);
        Output(&pc);//输入1时输出相乘的多项式
    case 2:
        Add(&pa, &pb, &pc);
        Output(&pc);
        Multiply(&pa, &pb);
        Output(&pc);//输入2时分别输出相加和相乘的多项式
    }
    system("pause");
    return 0;
}
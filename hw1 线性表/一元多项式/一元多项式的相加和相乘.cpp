#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
using namespace std;
 
struct Polynominal {
    float coef;    //ϵ��
    int expn;    //ָ��
    Polynominal* next;
};//����ʽ�洢

struct LinkList {
    Polynominal* data;
    LinkList* next;
}; //����



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
}//�������ʽ




void Add(LinkList* px, LinkList* qx��LinkList* rx)
{

}//����ʽ��Ӳ����������rx��




void Multiply(LinkList* px, LinkList* qx)
{

}//����ʽ��˲����������rx��



void Output(LinkList* p);
{

}




int main()
{
    LinkList pa, pb, pc;
    int m, n, i;
    cin >> m;
    Create(&pa, m);//�����һ������ʽ
    cin >> n;
    Create(&pb, n);//����ڶ�������ʽ
    Create(&pc, 0);//��ʼ��pc
    cin >> i;
    switch (i) {
    case 0:
        Add(&pa, &pb,&pc);
        Output(&pc);//����0ʱ�����ӵĶ���ʽ
    case 1:
        Multiply(&pa, &pb, &pc);
        Output(&pc);//����1ʱ�����˵Ķ���ʽ
    case 2:
        Add(&pa, &pb, &pc);
        Output(&pc);
        Multiply(&pa, &pb);
        Output(&pc);//����2ʱ�ֱ������Ӻ���˵Ķ���ʽ
    }
    system("pause");
    return 0;
}
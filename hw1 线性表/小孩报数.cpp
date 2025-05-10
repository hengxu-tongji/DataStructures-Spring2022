#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct node {
    int number;
    struct node * next;
}person;
person * initLink(int n) {
    int i = 0;
    person * head = NULL, *cyclic = NULL;
    head = (person*)malloc(sizeof(person));
    head->number = 1;
    head->next = NULL;
    cyclic = head;
    for (i = 2; i <= n; i++) {
        person * body = (person*)malloc(sizeof(person));
        body->number = i;
        body->next = NULL;
        cyclic->next = body;
        cyclic = cyclic->next;
    }
    cyclic->next = head;//��β����
    return head;
}
void findAndKillK(person * head, int k, int m) {
    person * p = NULL;
    person * tail = head;
    //�ҵ������һ��������һ����㣬Ϊɾ��������׼��
    while (tail->next != head) {
        tail = tail->next;
    }
    p = head;
    //�ҵ����Ϊk����
    while (p->number != k) {
        tail = p;
        p = p->next;
    }
    //�ӱ��Ϊk���˿�ʼ��ֻ�з���p->next==pʱ��˵�������г���p��㣬���б�Ŷ������ˣ�
    while (p->next != p) {
        int i = 0;
        //�ҵ���p����1��ʼ����m���ˣ����һ�Ҫ֪����m-1de�˵�λ��tail��������ɾ��������
        for (i = 1; i < m; i++) {
            tail = p;
            p = p->next;
        }
        tail->next = p->next;//�������Ͻ�p���ժ����
        cout << p->number << " ";
        free(p);
        p = tail->next;//����ʹ��pָ��ָ����б�ŵ���һ����ţ���Ϸ����
    }
    cout << p->number << endl;
    free(p);
}
int main()
{
    int n,s,m;
	cin >> n >> s >> m;
    person * head = NULL;
    head = initLink(n);
    findAndKillK(head, s, m);
    return 0;
}
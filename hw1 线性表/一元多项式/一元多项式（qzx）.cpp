#include <iostream>
using namespace std;
#define OK 0
#define ERROR -1
class LNode {
public:
	float data;
	int expn;
	LNode* next;
	LNode() {
		next = NULL;
	}
};
class LList {
public:
	LNode* head;
	LList() {
		head = new LNode;
		head->next = NULL;
	}
	int LL_insert(int i, float e, int _expn) {
		if (i < 1) return ERROR;
		int j = 1;
		LNode* p = head->next, * q = head;
		while (p && j < i) {
			q = p;
			p = p->next;
			j++;
		}
		if (!p && j < i) return ERROR;
		LNode* node = new LNode;
		node->data = e;
		node->expn = _expn;
		q->next = node;
		node->next = p;
		return OK;
	}
	int LL_delete(int i) {
		if (i < 1) return ERROR;
		int j = 1;
		LNode* p = head->next, * q = head;
		while (!p && j < i) {
			q = p;
			p = p->next;
			j++;
		}
		if (j <= i) return ERROR;
		q->next = p->next;
		return OK;
	}
	void LL_display() {
		LNode* p = head->next;
		while (p) {
			if (!p->data) {
				p = p->next;
				continue;
			}
			if (p != head->next) {
				cout << "";
			}
			if (p->data > 0 || p == head->next) {

				cout << p->data << " ";
			}
			else
				if (p->data != 0)
					cout << "" << p->data << " ";

			cout << p->expn << " ";
			p = p->next;
		}
		cout << endl;
	}
	float LL_circle() {
		LNode* p = head->next, * q;
		while (p->next != p) {
			q = p->next->next;
			p->next->next = q->next;
			p = p->next->next;
		}
		return p->data;
	}
	void LL_AddPolyn(LList& LLb);
	LList* LL_MulPolyn(LList& LLb);
	void LL_DeletePolyn();
};
void LList::LL_AddPolyn(LList& LLb) {
	LNode* pa = head->next; LNode* pb = LLb.head->next;
	LNode* ha = new LNode; LNode* pha = ha;             //ha作和链表的头节点，pha指向和链表末尾节点
	ha->expn = -1; ha->data = 0;
	while (pa && pb) {
		if (pa->expn > pb->expn) {
			pha->next = pb;
			pb = pb->next;
			pha = pha->next;
		}
		else if (pa->expn < pb->expn) {
			pha->next = pa;
			pa = pa->next;
			pha = pha->next;
		}
		else {
			float sum = pa->data + pb->data;
			if (sum != 0.0) {
				pa->data = sum;
				pha->next = pa;
				pa = pa->next;
				pha = pha->next;
			}
			else {
				LNode* tempa = pa;
				pa = pa->next;
				delete tempa;
			}
			LNode* tempb = pb;
			pb = pb->next;
			delete tempb;
		}
	}
	while (pa) {
		pha->next = pa;
		pa = pa->next;
		pha = pha->next;
	}
	while (pb) {
		pha->next = pb;
		pb = pb->next;
		pha = pha->next;
	}
	pha->next = NULL;
	head = ha;
}
LList* LList::LL_MulPolyn(LList& LLb) {
	LNode* pa = head->next;
	LList* AList = new LList;                         //累加
	AList->head->data = 0; AList->head->expn = -1;
	while (pa) {
		LList MList;                                //逐项相乘
		int i = 1;
		LNode* pb = LLb.head->next;
		while (pb) {
			float m_data;
			int m_expn;
			m_data = pa->data * pb->data;
			m_expn = pa->expn + pb->expn;
			MList.LL_insert(i++, m_data, m_expn);
			if (pa == head->next)
				AList->LL_insert(i - 1, 0, 0);
			pb = pb->next;
		}
		AList->LL_AddPolyn(MList);
		pa = pa->next;
	}
	return AList;
}
void LList::LL_DeletePolyn() {
	LNode* p = head->next;
	while (p) {
		LNode* q = p;
		p = p->next;
		delete q;
	}
}
int main() {
	LList list;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		float data;
		int expn;
		cin >> data >> expn;
		list.LL_insert(i + 1, data, expn);
	}
	LList listb;
	cin >> n;
	for (int i = 0; i < n; i++) {
		float data;
		int expn;
		cin >> data >> expn;
		listb.LL_insert(i + 1, data, expn);
	}
	LList* mulList = list.LL_MulPolyn(listb);
	//cout << "["; list.LL_display(); cout << "]"; cout << "*"; cout << "["; listb.LL_display(); cout << "]"; cout << "=";
	int tt;
	cin >> tt;
	if (tt == 0)
	{
		list.LL_AddPolyn(listb);
		list.LL_display();

	}
	else if (tt == 1)
	{
		mulList->LL_display();

	}
	else if (tt == 2)
	{
		list.LL_AddPolyn(listb);
		list.LL_display();
		mulList->LL_display();


	}
	list.LL_DeletePolyn(); //删除整一条和链表
	return 0;
}

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct term
{
    float coef;
    int expn;};
typedef struct LNode{
    term elem;
    struct LNode *next;
}LNode,*polynomial;
void CreatPolyn(polynomial &P,int m){
	polynomial p,r;
	P=(polynomial)malloc(sizeof(LNode));
	P->next = NULL;
	r=P;
	for (int i=0;i<m;i++) {
		p=(polynomial)malloc(sizeof(LNode));
		cin>>p->elem.coef>>p->elem.expn;
		fflush(stdin);
		r->next=p; r=p; }
	r->next=NULL;
}
void SortPolyn(polynomial &P){
	polynomial p,q;
	term a;
	for(p=P->next;p!=NULL;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(p->elem.expn>q->elem.expn)
			{ a=p->elem;
			  p->elem=q->elem;
			  q->elem=a;}}}
}
void PrintPolyn(polynomial P){
	polynomial p;
	for(p=P->next;p!=NULL;p=p->next)
		if (p->elem.coef != 0 || p->elem.expn != 0) {
			cout << p->elem.coef << ' ' << p->elem.expn << ' ';
			fflush(stdout);
		}
}
void AddPolyn(polynomial &Pa,polynomial &Pb){
	polynomial ha,hb,qa,qb;
	ha=Pa; hb=Pb;
	qa=ha->next; qb=hb->next;
	while(qa&&qb){
		term a=qa->elem,b=qb->elem;
		if(a.expn<b.expn) {ha=qa;qa=qa->next;}
		else if(a.expn>b.expn) 
		{hb->next=qb->next;
		 qb->next=ha->next;ha->next=qb;
		 qb=hb->next;
		 ha=ha->next;}
		else {float sum=a.coef+b.coef;
		   if(sum!=0.0){ qa->elem.coef=sum;ha=qa;}
		   else {ha->next=qa->next;free(qa);}
		   hb->next=qb->next;free(qb);qb=hb->next;qa=ha->next;}}
	if(qa==NULL) ha->next=qb;
	free(hb);
}
void MultiplyPolyn(polynomial &Pa,polynomial &Pb){
	polynomial pa,pb,Pc,Pd,p,r;
	term a,b;
	Pc=(polynomial)malloc(sizeof(LNode));
	Pc->next=NULL;
	for(pb=Pb->next;pb!=NULL;pb=pb->next)
	{  b=pb->elem;
	   Pd=(polynomial)malloc(sizeof(LNode));
	   Pd->next=NULL; r=Pd;
	   for(pa=Pa->next;pa!=NULL;pa=pa->next)
	   {  a=pa->elem;
	      p=(polynomial)malloc(sizeof(LNode));
	      p->elem.coef=a.coef*b.coef;
		  p->elem.expn=a.expn+b.expn;
	      r->next=p; r=p;}
	   r->next=NULL;
	   AddPolyn(Pc,Pd);}
	free(Pa);free(Pb);
	Pa=Pc;
}
int main(){
	int m,n,i;
	char c;
	polynomial Pa,Pb;
	cin>>m;
	CreatPolyn(Pa,m);
	cin>>n;
	CreatPolyn(Pb,n);
	SortPolyn(Pa);
	SortPolyn(Pb);
	cin>>c;
	switch(c){
	case '0':{AddPolyn(Pa,Pb); PrintPolyn(Pa);} break;
	case '1':{MultiplyPolyn(Pa,Pb); PrintPolyn(Pa);} break;
	case '2':
		{polynomial Pc,Pd,p,r,q;
		 Pc=(polynomial)malloc(sizeof(LNode));
	     Pc->next=NULL; r=Pc;
	     for(q=Pa->next;q!=NULL;q=q->next)
	     {  p=(polynomial)malloc(sizeof(LNode));
	        p->elem.coef=q->elem.coef;
		    p->elem.expn=q->elem.expn;
	        r->next=p; r=p;}
	        r->next=NULL;
		 Pd=(polynomial)malloc(sizeof(LNode));
	     Pd->next=NULL; r=Pd;
	     for(q=Pb->next;q!=NULL;q=q->next)
	     {  p=(polynomial)malloc(sizeof(LNode));
	        p->elem.coef=q->elem.coef;
		    p->elem.expn=q->elem.expn;
	        r->next=p; r=p;}
	        r->next=NULL;
			AddPolyn(Pa,Pb); MultiplyPolyn(Pc,Pd);
		    PrintPolyn(Pa); cout<<endl; PrintPolyn(Pc);} break;}
	return 0;
}
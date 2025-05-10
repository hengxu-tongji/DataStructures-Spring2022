#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<map>
#include<istream>
#include<cstdio>
using namespace std;
#define STACK_INIT_SIZE 10000
map<char,int>mp;// ! & | ( £©#
char p[7][7]={{'=','>','>','<','>','>'},  // £¡
              {'<','>','>','<','>','>'},  // &
              {'<','<','>','<','>','>'},  // |
              {'<','<','<','<','=','0'},  //£¨
              {'>','>','>','0','>','>'},  // )
              {'<','<','<','<','0','='},};// #
typedef struct{
    char *base;
    char *top;
    int stacksize;
}SqStack;
int InitStack(SqStack &S) {
    S.base=(char *)malloc(STACK_INIT_SIZE*sizeof(char));
    if (!S.base) return -1;
    S.top=S.base;
    S.stacksize = STACK_INIT_SIZE;
    return 0;
}
int Push(SqStack &S,char e)
{
    if (S.top-S.base>=S.stacksize) return -1;
    *S.top++=e;
    return 0;
}
int Pop(SqStack &S,char &e)
{
    if(S.top==S.base) return -1;
    e=*--S.top;
    return 0;
}
char Precede(char a,char b){
    int ida,idb;
    ida=mp[a];
    idb=mp[b];
    return p[ida][idb];
}
char Operate1(char a,char b,char theta){
    int a1,b1;
    if(a=='V') a1=1;
    else a1=0;
    if(b=='V') b1=1;
    else b1=0;
    if(theta=='|') a1=(a1||b1);
    else if(theta=='&') a1=(a1&&b1);
    if(a1==0) return 'F';
    else return 'V';
}
char Operate2(char a,char theta){
    if(a=='V') return 'F';
    else return 'V';
}
int EvaluateExpression(string s){
    SqStack OPTR,OPND;
    char x,theta,a,b;
    int i=0,len;
    InitStack(OPTR);
    Push(OPTR,'#');
    InitStack(OPND);
    len=s.length();
    while((s[i]!='#'||*(OPTR.top-1)!='#')&&i<len){
        if(s[i]=='V'||s[i]=='F'){Push(OPND,s[i]);i++;}
        else
            switch(Precede(*(OPTR.top-1),s[i])){
            case '<':
                Push(OPTR,s[i]); i++;
                break;
            case '=':
                Pop(OPTR,x); i++;
                break;
            case '>':
                Pop(OPTR,theta); 
                if(theta=='!') {Pop(OPND,a);Push(OPND,Operate2(a,theta));}
                else {Pop(OPND,b);Pop(OPND,a);Push(OPND,Operate1(a,b,theta));}
                break;}
        }
        cout<<*(OPND.top-1)<<endl;
        return 0;
}
int main(){
    mp['!']=0;mp['&']=1;mp['|']=2;mp['(']=3;mp[')']=4;mp['#']=5;
    string s,temp;
    int i=1,j;
    while(getline(cin,s)){
        j=0;temp="";
        while(j<s.length()){
			while(s[j]==' ') j++;
			if(s[j]=='\r') break;
            temp+=s[j];j++;}
        temp+="#";
        cout<<"Expression"<<' '<<i<<':'<<' ';
        i++;
        EvaluateExpression(temp);
    }
    return 0;
}
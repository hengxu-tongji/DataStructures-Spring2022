#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct Tri{
	char data;
	int left,right;
}T1[10101],T2[10101];
int judge(int m,int n){
	if(m==-1&&n==-1) return 1;
	else if(m!=-1&&n!=-1){
		if(T1[m].data==T2[n].data){
			if((judge(T1[m].left,T2[n].left)&&judge(T1[m].right,T2[n].right))||(judge(T1[m].left,T2[n].right)&&judge(T1[m].right,T2[n].left)))
				return 1;}
		else return 0;}
	else return 0;
}
int CreateTree(Tri *T){
	char l[4],r[4];
	int N,i,flag[10101];
	cin>>N;
	getchar();
	if(N){
		for(i=0;i<N;i++)  flag[i]=1;
		for(i=0;i<N;i++){
			cin>>T[i].data>>l>>r;
			if(strcmp(l,"-")==0) T[i].left=-1;
			else{
				T[i].left=atoi(l);
				flag[T[i].left]=-1;}
			if(strcmp(r,"-")==0) T[i].right=-1;
			else{
				T[i].right=atoi(r);
				flag[T[i].right]=-1;}
		}
		for(i=0;i<N;i++){
			if(flag[i]==1)
				return i;}
		return -1;
	}
	return -1;
}
int coutlevel1(int m){
	if(m==-1) return 0;
	return max(coutlevel1(T1[m].left),coutlevel1(T1[m].right))+1;
}
int coutlevel2(int n){
	if(n==-1) return 0;
	return max(coutlevel2(T2[n].left),coutlevel2(T2[n].right))+1;
}
int main(){
	int m,n;
	m=CreateTree(T1);
	n=CreateTree(T2);
	if(judge(m,n)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	cout<<coutlevel1(m)<<endl<<coutlevel2(n)<<endl;
	return 0;
}
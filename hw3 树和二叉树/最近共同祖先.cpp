#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main(){
	int N,i,j,k,n,m,p[1002],a,b,root;
	int A[1002],B[1002];
	cin>>N;
	for(i=0;i<N;i++){
		cin>>n>>m;
		for(root=1;root<n+1;root++) p[root]=-1;
		for(root=1;root<n;root++){
			cin>>a>>b;
			p[b]=a;}
		for(root=1;root<n+1;root++){
			if(p[root]==-1) break;}
		for(k=0;k<m;k++){
		cin>>A[0]>>B[0];
		for(j=0;A[j]!=root;j++) A[j+1]=p[A[j]];
		a=j+1;
		for(j=0;B[j]!=root;j++) B[j+1]=p[B[j]];
		b=j+1;
		if(a<b)
			for(j=0;j<a;j++){
				if(A[j]==B[j+b-a]){
					cout<<A[j]<<endl;
					break;}}
		else
			for(j=0;j<b;j++){
				if(A[j+a-b]==B[j]){
					cout<<B[j]<<endl;
					break;}}}
	}
	return 0;
}
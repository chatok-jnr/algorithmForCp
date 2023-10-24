#include<bits/stdc++.h>
using namespace std;


const int mx=1e6+123;
int parent[mx],Rank[mx];

void make_set(int x){
	parent[x]=x;
	Rank[x]=1;
}

int find_set(int v){
	if(v==parent[v]) return v;
	return parent[v]=find_set(parent[v]);
}

void union_set(int a,int b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b)parent[a]=b;
}
int main(){
	int n,m;	cin>>n>>m;
	for(int i=1;i<=n;i++)make_set(i);
	for(int i=0;i<m;i++){
		int u,v;	cin>>u>>v;
		union_set(u,v);
	}
	bool chk=1;
	for(int i=1;i<=n/2;i++){
		int a=find_set(i);
		int b=find_set(n-i+1);
		if(a!=b){
			chk=0;
			break;
		}
	}
	chk?cout<<"Yes"<<endl:cout<<"No"<<endl;
	return 0;
}
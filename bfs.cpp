#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+123;
vector<int>adj[mx];
int lev[mx];

void bfs(int src){
    memset(lev,-1,sizeof(lev));
    lev[src]=0;
    queue<int>q;
    q.push(src);
    while (!q.empty())
    {
        int v=q.front();
        q.pop();
        for(auto u:adj[v]){
           if(lev[u]==-1){
             q.push(u); 
             lev[u]=lev[v]+1;
           }
        }
    }
    
}

int main(){
    int t;  cin>>t;
    while (t--)
    {
      int n,m;  cin>>n>>m;
      for(int i=0;i<n;i++){
         int u,v;   cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
    }
    
    
    return 0;
}
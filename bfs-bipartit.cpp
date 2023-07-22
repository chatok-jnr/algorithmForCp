#include<bits/stdc++.h>
using namespace std;
#define Hayai() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mx=201;
vector<long long>adj[mx];
int col[mx];
bool isBipartit(long long src);

int main(){
    Hayai();
    //int t;  
  //  while(cin>>t){
       //if(t==0) break;
        int n;  cin>>n;
        for(int i=0;i<n;i++){
            long long u,v;  cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(isBipartit(0))cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
      //  for(int i=0;i<=t;i++)adj[i].clear();
   // }

    return 0;
}

bool isBipartit(long long src){
  //  for(int i=0;i<mx;i++)col[i]=0;
    col[0]=1;
    queue<long long>q;
    q.push(src);
    while(!q.empty()){
        long long u=q.front();
        q.pop();
        for(auto v:adj[u]){
           if(col[v]==col[u])return false;
           else if(col[v]==0){
              q.push(v);
            if(col[u]==1) col[v]=2;
            else col[v]=1;
           }
        }
    }
    return true;
}
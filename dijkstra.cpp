#include<bits/stdc++.h>
using namespace std;

const long long IF=90000000000000000;
const int mx=1e5+123;

long long dist[mx];
vector<pair<int,int>>adj[mx];

void dijkastra(int s,int n){
    for(int i=1;i<=n;i++)dist[i]=IF;//initialize
    dist[s]=0;//initialize sourc distance
   priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;//pushing source in queue
   /*because of uses of greater this priorito queue will be 
   work as reversse the smalles value will be the toppest value*/
   
    pq.push({0,s});
    
    while(!pq.empty()){
        int u=pq.top().second;
        long long currentDistance=pq.top().first;
        pq.pop();

        if(dist[u]<currentDistance)continue;//important

        for(auto p:adj[u]){
            int v=p.first;
            long long cost=p.second;

            if(currentDistance+cost<dist[v]){//relax operation
                dist[v]=currentDistance+cost;
                pq.push({dist[v],v});
            }
        }
    }
}

int main(){
    int node,edge;  cin>>node>>edge;

    for(int i=0;i<edge;i++){
        int u,v,cost;   cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
    }

    dijkastra(1,node); //to calculate the distance between source node to rest of the nodes

    for(int i=1;i<=node;i++){
        cout<<"From 1 to "<<i<<" = "<<dist[i]<<"\n";
    }
    cout<<"\n";

    return 0;
}
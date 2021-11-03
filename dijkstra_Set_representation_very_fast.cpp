#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int INF =1e18;
vector<pair<int,int>>adj[100005];

void dijkstra(int s,vector<int>&d,vector<int>&p){
    d[s]=0;
    set<pair<int,int>> q;
    q.insert({d[s],s});

    while(!q.empty()){
     int v = q.begin()->second;
             q.erase(q.begin());

     for(auto &[to,len]:adj[v]){
         if(d[v]+len<d[to]){
            q.erase({d[to],to});
            d[to]=d[v]+len;
            p[to]=v;
            q.insert({d[to],to});
      }
    }
  }
}
signed main(){
    int n,m,q; 
    cin>>n>>m>>q;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back({b,0});
        adj[b].push_back({a,1});
    }
    vector<int>d(100005,INF),p(100005,-1);
    dijkstra(1,d,p);
    while(q--){
        int u,v;
        cin>>u>>v;
        if(d[v]==INF)cout<<-1<<endl;
        else cout<<d[v]<<endl;
    }
  return 0;
}
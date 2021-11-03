//dijkstra Algorithm 
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj[1001];  //pair type adj list

void dijkstra(int src,vector<int> & dist)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,src});
   dist[src]=0;
  while(!pq.empty()){
  int curr=pq.top().second;
  int current_distance=pq.top().first;
  pq.pop();
  for(pair<int,int> kid:adj[curr]){
      if(current_distance+kid.second < dist[kid.first]){
          dist[kid.first]=current_distance+kid.second;
          pq.push({dist[kid.first],kid.first});
      }
    }
  }
}
 int main(){
	int n,m; //nodes and edges
	cin>>n>>m;
	while(m--){
		int a,b,w;  //node-node-weight 
		cin>>a>>b>>w;
		adj[a].push_back({b,w});
		adj[b].push_back({a,w});
	}

vector<int>dist(n+1,INT_MAX);
int src; //manually passing the source vertex in the dijkstra function 
cin>>src;
dijkstra(src,dist);  //calling dijkstra function in the main() function 
for(int i=1;i<=n;i++)
cout<<dist[i]<<" ";
}
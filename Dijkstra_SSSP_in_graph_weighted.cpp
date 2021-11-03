//dijkstra Algorithm 

#include<bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
vector<pii>adj[1001]; //Pair type adjacency List 
void dijkstra(int src,vector<int>&dist)
{
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
 pq.push({0,src});
 dist[src]=0;
  while(!pq.empty()){
  int curr=pq.top().s;
  int current_distance=pq.top().f;
  pq.pop();
  for(pii kid:adj[curr]){
      if(current_distance+kid.s < dist[kid.f]){
          dist[kid.f]=current_distance+kid.s;
          pq.push({dist[kid.f],kid.f});  // ( dist ,node )
      }
    }
  }
}
 int main(){
  int test;
  cin>>test;
  while(test--)
  {
	int n,q,m; //nodes and edges
	cin>>n>>q>>m;
	while(m--){
		int a,b,w;  //node-node-weight 
		cin>>a>>b>>w;
		adj[a].push_back({b,w});
		adj[b].push_back({a,w});
	}
vector<int>dist(n+1,INT_MAX);
int src; //manually passing the source vertex in the dijkstra function 
cin>>src;
while(q--)
{
  int U,V;
  cin>>U>>V;
dijkstra(U,dist);  //calling dijkstra function in the main() function 
for(int i=1;i<=n;i++)
cout<<dist[i]<<" ";
  }
 }
}
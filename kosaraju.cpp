// For strongly connected components
#include<bits/stdc++.h>
using namespace std;
vector<int> *adj=new vector<int>[10001];  // adjacency list for graph
vector<int> *transpose=new vector<int>[10001];  // adjacency list for transpose graph
int visited[10001];
vector<int>order;   // nodes in increasing order of leaving time
vector<int>scc;     // strongly connected components 

// this dfs function is recursively call for visiting all nodes and note the out time for nodes   
void dfs(int node)
{
    visited[node]=1;
    for(int child:adj[node])
        if(visited[child]==0)
            dfs(child);
    order.push_back(node);      // pushing nodes in vector according to leaving time of node 
}

// normal dfs function for transpose graph so that we can count the strongly connected component
void dfs1(int node)
{
    visited[node]=1;
    for(int child:transpose[node])
        if(visited[child]==0)
            dfs1(child);
    scc.push_back(node);        // pushing nodes of strongly connected components         
}

// driver's code 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n>>e;

        // flushing all the vectors
        for(int i=1;i<=n;i++)
        {
            visited[i]=0;
            adj[i].clear();
            transpose[i].clear();
            order.clear();
        }

        // directed graph 
        for(int i=1;i<=e;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            transpose[v].push_back(u);
        }

        for(int i=1;i<=n;i++)
            if(visited[i]==0)
                dfs(i);
        
        // making visted array unvisited
        for(int i=1;i<=n;i++)
            visited[i]=0;
        
        // calling dfs1 function for traversing tranpose graph
        for(int i=1;i<=n;i++)
        {
            if(visited[order[n-i]]==0)
            {
                scc.clear();
                dfs1(order[n-i]);
                cout<<"dfs1 called from "<<order[n-i]<<" and printing scc"<<endl;
                for(int node:scc)
                    cout<<node<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}
// driver code ends here...
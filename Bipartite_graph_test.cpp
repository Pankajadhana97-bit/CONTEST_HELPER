//bipartate graph test 
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e3;
vector<int>graph[N];
bool vis[N];
int col[N];

bool dfs(int src,int c){
	vis[src]=true;
	col[src]=c;

	for(auto child: graph[src]){
		if(!vis[child]){
			if(dfs(child,~c)==false)
				return false;
		}
		else{
			if(col[src]==col[child])
				return false;
		}
	}
	return true;
}

signed main(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cout<<(dfs(1,-1)?"YES":"NO")<<endl;
}

// 4 4 
// 1 2
// 2 3
// 3 4
// 1 4 
// Input for the question (or you can say concept)
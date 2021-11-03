#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>arr[100];
bool vis[100];
int col[100];

bool bfsbipartite(int node){
	queue<int>q;
	q.push(node);
	col[node]=1;

	while(!q.empty()){
		int src=q.front();
		        q.pop();
		 for(auto child:arr[src]){
		 	   if(col[child]==-1){
		 	   	   col[child]=1-col[src];
		 	   	   q.push(child);
		 	   }
		 	   else if(col[child]==col[src]){
		 	   return false;
		 	   }
		 }
	}
	return true;
}
void solve(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	memset(col,-1,sizeof(col));
	cout<<bfsbipartite(1); 
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
  cerr<<"Time elapsed : "<<1.0*clock()/CLOCKS_PER_SEC<<" sec\n";
}
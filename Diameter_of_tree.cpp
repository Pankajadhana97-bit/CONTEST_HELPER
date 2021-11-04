#include<bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef DEBUGGER
#define deb(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define deb(...)
#endif
 
const int N = 1e5+10;
vector<int>graph[N];
vector<int>depth(N,0);

void dfs(int src,int parent = -1){
    for(auto child:graph[src]){
      if(child==parent) continue;
      depth[child]=depth[src]+1;
      dfs(child,src);
    }
}

void solve(){

  int n;
  cin>>n;
  for(int i=1;i<n;i++){
   int a,b; cin>>a>>b;
   graph[a].push_back(b);
   graph[b].push_back(a);
  }

  dfs(1);
  int max_node=-1;
  int max_dist=-1;
  for(int i=1;i<=n;i++){
      if(depth[i]>max_dist){
        max_node=i;
        max_dist=depth[i];
      }
      depth[i]=0;
  }

  cout<<max_node<<"\n";
  dfs(max_node);
  for(int i=1;i<=n;i++){
      if(depth[i]>max_dist){
        max_node=i;
        max_dist=depth[i];
      }
      depth[i]=0;
  }
  cout<<max_node<<"\n";
  cout<<max_dist<<endl;
  return;
}
signed main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef DEBUGGER
    freopen("error.txt", "w", stderr);
    #endif
    
    solve();
  cerr<<"[Time elapsed : "<<(double)clock()/CLOCKS_PER_SEC<<"]\n";
}
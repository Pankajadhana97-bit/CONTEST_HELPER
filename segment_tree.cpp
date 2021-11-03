#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,q;
vector<int>A,tree,lazy; 
void propagate(int i,int start,int end){
    tree[i]+=lazy[i]*(end-start+1);
    if(start!=end){
      lazy[2*i]+=lazy[i];
      lazy[2*i+1]+=lazy[i];
  }
  lazy[i]=0;
}
int query(int i,int start,int end,int low,int high){
  if(lazy[i] != 0) propagate(i,start,end);
  if(start>high or low>end or  start>end ) return 0;
  if(start>=low and end<=high){
    return tree[i];
  }
  int mid=(start+end)>>1;
  int q1=query(2*i,start,mid,low,high);
  int q2=query(2*i+1,mid+1,end,low,high);
  return (q1+q2);
}

void update(int i,int start,int end,int low,int high,int val){

  if(lazy[i]!=0)propagate(i,start,end);
  if(start>high or low>end or  start>end ) return;
  if(start>=low and end<=high){
    lazy[i]=val;
    propagate(i,start,end);
    return;
  }
  int mid=(start+end)>>1;
  update(2*i,start,mid,low,high,val);
  update(2*i+1,mid+1,end,low,high,val);
  tree[i]=tree[2*i]+tree[2*i+1];
}
void update(int low,int high,int val){
  update(1,0,n-1,low-1,high-1,val);
}
int query(int low,int high){
  return query(1,0,n-1,low-1,high-1);
}

void solve(){
  cin>>n>>q;
  A.resize(n);
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  while(__builtin_popcount(n) != 1){
    n++;
    A.push_back(0);
  }
  tree.resize(2*n);
  lazy.resize(2*n);
  for(int i=0;i<n;i++){
    tree[n+i]=A[i];
  }
  for(int i=n-1;i>0;i--){
    tree[i]=tree[2*i]+tree[2*i+1];
  }
  while(q--){
   int a,b,c,d;
   cin>>a;
   if(a==1){
    cin>>b>>c>>d;
    update(b,c,d);
   }
   else if(a==2){
    cin>>b>>c>>d;
    cout<<query(b,b)<<"\n";
   }
  }
  return; 
}
signed main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
  cerr<<"[Time elapsed : "<<(double)clock()/CLOCKS_PER_SEC<<"]\n";
}
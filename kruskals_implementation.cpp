#include<bits/stdc++.h>
/*
Pankaj Adhana
Panjab university;
*/
/* Defined values----------------------------------------------------  */
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define cases long long int t=1;cin>>t; while(t--) { solve();} return 0
#define ll long long int
#define all(v) v.begin(),v.end()
/* -------------------------------------------------------------------- */
using namespace std;
const int N=10e5;
struct edge
{
 int a;
 int b;
 int w;	
};
edge arr[N];
int parent[N];
int Rank[N];
int sum=0;

int find(int a){
	if(a==parent[a])
		return a;
	return parent[a]=find(parent[a]);
}
void connect(int a,int b){ 
      if(Rank[a]<Rank[b])
      	 swap(a,b);
      	parent[b]=a;
       if(Rank[a]==Rank[b])
      		Rank[a]++;
}
bool comp(edge a,edge b){
	if(a.w<b.w)
		return true;
		return false;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){  // validation succesful
		parent[i]=i;
	}
	for(int i=0;i<m;i++){
		cin>>arr[i].a>>arr[i].b>>arr[i].w;
	} 
	sort(arr,arr+m,comp);
	for(int i=0;i<m;i++){
		 int a=find(arr[i].a);
		 int b=find(arr[i].b);
		 if(a!=b){
			sum+=arr[i].w;
			connect(a,b);
		}
	}
	cout<<sum<<endl;
}
int main()
{
fast_io;
//cases;
solve();
}
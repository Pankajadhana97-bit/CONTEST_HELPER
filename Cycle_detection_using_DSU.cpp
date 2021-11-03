#include<iostream>
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
int parent[N];
int Rank[N];

int find(int a){
	if(a==parent[a])
		return a;
	return parent[a]=find(parent[a]);
}
void connect(int a,int b){
	if(Rank[a]<Rank[b]){
		parent[a]=b;
		Rank[b]++;
	}
	else{
		parent[b]=a;
		Rank[a]++;
	}
}

void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		parent[i]=i;
	}
	bool flag=false;
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		a=find(a);
		b=find(b);
		if(a!=b){
			connect(a,b);
		}
		else{
		 flag=true;
		}
	}
	if(flag==true)cout<<"YES THE GRAPH CONTAIN CYCLE"<<endl;
	else cout<<"NO IT DOESN'T"<<endl;
}
int main()
{
fast_io;
solve();
}
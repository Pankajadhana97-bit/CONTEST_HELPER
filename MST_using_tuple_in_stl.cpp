//kruskals implementation 
#include<bits/stdc++.h>

using namespace std;
const int N=1e5;

vector<tuple<int,int,int>>arr;
int parent[N];
int Rank[N];

int find(int a){
	if(a==parent[a])
		return a;
	return parent[a]=find(parent[a]);
}
void connect(int a,int b){
	if(Rank[a]<Rank[b])
		   swap(a,b);
		  parent[b]=a;
		  if(Rank[a]==Rank[b]){
		  	Rank[a]++;
		  }
}
bool comp(const tuple<int,int,int>& a,const tuple<int,int,int>& b) { 
    return (get<2>(a) < get<2>(b)); 
} 

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		parent[i]=i;
	}
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		arr.push_back({a,b,c});
	}
	sort(arr.begin(),arr.end(),comp);
	int sum=0;
	for(auto [a,b,c]:arr){
		
		a=find(a);
		b=find(b);
		if(a!=b){
			sum+=c;
			connect(a,b);
		}
	}
 cout<<sum<<endl;
}




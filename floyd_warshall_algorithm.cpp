#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[1000][1000];
void floyd(int n){
	for(int k=0;k<=n;k++){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
			 if(arr[k][j] < INT_MAX and arr[i][k] < INT_MAX )
              arr[i][j]=min(arr[i][j],arr[k][j]+arr[i][k]);
			}
		}
	}
}
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
             arr[i][j]=INT_MAX;
		}
	}
	while(m--){
		int a,b,w;
		cin>>a>>b>>w;
		arr[a][b]=min(arr[a][b],w);
		arr[b][a]=min(arr[b][a],w);
	}
	floyd(n); 
	int src,dest;
	cin>>src>>dest;
	for(int i=1;i<=n;i++){
		if(arr[src][i]==INT_MAX)
			cout<<-1<<" ";
		else
	        cout<<arr[src][i]<<" ";
    }
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int INF =1e18;
int dp[3001][3001];
void Floyd_warshal(int n){
   for(int i=1;i<=n;i++) dp[i][i]=0; //same-same (0 distance)

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }
}

signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<3001;i++){
        for(int j=0;j<3001;j++){
            dp[i][j]=INF;
        }
    }
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        dp[a][b]=min(dp[a][b],w);
        dp[b][a]=min(dp[b][a],w);
    }
    Floyd_warshal(n);
    for(int i=1;i<=n;i++){
        int u=1;
        int v=i;
       if(dp[u][v]!=INF) cout<<dp[u][v]<<endl;
       else cout<<-1<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[101][101][2];

int digitDP(string &nums,int n,int x,bool tight){
  if(x<0) return 0;
  if(n==1){
    if(x>=0 and x<=9){
      return 1;
    }
    return 0;
  }
  if(dp[n][x][tight]!= -1){
    return dp[n][x][tight];
  }
  int answer=0;
  int ub = tight ? nums[nums.size()-n]-'0':9;
   for(int i=0;i<=ub;i++){
    answer+=digitDP(nums,n-1,x-i,tight &(i==ub));
   }
   return  dp[n][x][tight]=answer;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    string num;
    cin>>num;
    int x;
    cin>>x;
    int ans=digitDP(num,num.length(),x,1);
    cout<<ans<<"\n";
}
signed main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
  cerr<<"[Time elapsed : "<<(double)clock()/CLOCKS_PER_SEC<<"]\n";
}
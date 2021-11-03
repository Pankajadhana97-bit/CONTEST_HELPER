#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<bool> isprime;

void sieve(int n){
    isprime.resize(n+1);
    for (int i =2;i<=n;i++)
        isprime[i] = true;
    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i <= n; i++){
        for (int j = 2 * i; j <= n; j += i){
            isprime[j] = false;
           }
        }
    return;
} //Please declare the sieve in the main funtion with the 1e6 ;

void solve(){
    
}
signed main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
  cerr<<"[Time elapsed : "<<1.0*clock()/CLOCKS_PER_SEC<<"]\n";
}
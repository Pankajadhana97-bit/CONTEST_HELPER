#include<bits/stdc++.h>
using namespace std;
#define int long long

//---------------------------------sieve of eratothenes------------------------------//
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

signed main(){
	sieve(1e6);
	vector<int> prime;
	for (int i = 0; i < 100;i++){
		if(isprime[i])prime.push_back(i);
	}
	for(auto x:prime)
		cout << x << " ";

	return 0;		
}
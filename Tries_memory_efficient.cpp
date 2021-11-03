#include<iostream>
#include<chrono>
#include<unordered_map>
using namespace std;
#define int long long

class TrieNode{
public:
    bool isend;
    unordered_map<char,TrieNode*>child;
    TrieNode(){
      isend=false;
    }
}*root;

void insert(string &s){
   TrieNode* curr=root;
  for(auto c:s){
    if(!curr->child[c])curr->child[c]=new TrieNode();
    curr=curr->child[c];
  }
  curr->isend=true;
}
bool search(string &s){
    TrieNode* curr=root;
   for(auto c:s){
    if(!curr->child[c])return false;
      curr=curr->child[c];
   }
   return curr->isend;
}
void solve(){
  root=new TrieNode();
  int n;
  cin>>n;
  while(n--){
    string s;
    cin>>s;
    insert(s);
  }
  string str;
  cin>>str;
  cout<<(search(str)?"YES":"NO");
  cout<<"\n";
}
signed main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
   // cin>>T;
    while(T--){
        solve();
    }
  cerr<<"[Time elapsed : "<<1.0*clock()/CLOCKS_PER_SEC<<"]\n";
}
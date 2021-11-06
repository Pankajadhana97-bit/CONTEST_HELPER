#include<bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef DEBUGGER
#define deb(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define deb(...)
#endif

// Defination of the binary tree
class Node{
public:
  Node* left;
  Node* right;
  int val;

  Node(int val){
    this->val = val;
    left = right = nullptr;
  }
}*root=nullptr;


Node* insert(Node* root,int value){
  if(!root){
    root = new Node(value);
    return root;
  }
  (root->val < value) ? root->right = insert(root->right,value) : root->left=insert(root->left,value);
  return root;
}

/**
* 
*      4             
*    /   \
*   2     6
*  / \   / \
* 1   3 5   7
* 
* */

void iterativeInorder(Node* root){
   Node* current=root;
   stack<Node*>st;
   while(true)
   {
      if(current != nullptr){
        st.push(current);
        current=current->left;
      }
      else{
         if(st.empty()){
          break;
         }
         current = st.top();
         cout<<current->val<<" ";
         st.pop();
         current=current->right;
      }
   }
}

void iterativePreorder(Node *root){
  if(!root) return;

  stack<Node*>st;
  st.push(root);

  while(st.empty()==false){
    Node* current = st.top(); st.pop();
    cout<<current->val<<" ";

    if(current->right)st.push(current->right);
    if(current->left) st.push(current->left);
  }
}

int solve(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    int val; cin>>val;
    root = insert(root,val);
  }
  cout<<"inorder -> ";
  iterativeInorder(root); cout<<"\n";
  cout<<"Preorder -> ";
  iterativePreorder(root); cout<<"\n";
  //iterativePostorder(root); cout<<"\n";
  return 0;
}

// no need to deal with this 
signed main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef DEBUGGER
    freopen("error.txt", "w", stderr);
    #endif
    
    solve();
  cerr<<"(Time):"<<(double)clock()/CLOCKS_PER_SEC<<"\n";
}
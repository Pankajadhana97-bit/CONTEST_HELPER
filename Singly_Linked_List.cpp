#include<bits/stdc++.h>
using namespace std;
#define int long long

class node{
public:
	int data;
	node* next;
	node(int val){
		data=val;
		next=NULL;
	}
};
node* head=NULL;
void insert(node* &head,int val){
	node* newnode=new node(val);

	if(head==NULL){
		head=newnode;
		return;
	}
	node* temp=head;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=newnode;
}
void display(node* &head){
	node* temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void insert_at_begin(node* &head,int val){
	node* newnode=new node(val);
	newnode->next=head;
	head=newnode;
}
void deletion(node* &head,int val){
	if(head==NULL){
		return;
	}
	else if(head->next==NULL){
		delete_at_head(head);
		return;
	}
	node* temp=head;
	while(temp->next->data!=val){
		temp=temp->next;
	}
	node* todelete=temp->next;
	temp->next=temp->next->next;
	delete todelete;
}
void delete_at_head(node* &head){
	node* todelete=head;
	head=head->next;

	delete todelete;
}
void solve(){
	int n;
	cin>>n;
	while(n--){
		int val;
		cin>>val;
		insert(head,val);
	}
	insert_at_begin(head,0);
	deletion(head,4);
	//delete_at_head(head);

	display(head); 
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
  cerr<<"Time elapsed : "<<1.0*clock()/CLOCKS_PER_SEC<<" sec\n";
}
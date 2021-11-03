#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};
node *newNode(int data)
{
	node* newnode=new node();
	newnode->data=data;
	newnode->left = NULL;
	newnode->right = NULL;
return newnode;
}
node *insert(node *root, int data)
{
	if(!root)
	{
		root = newNode(data);
	}
	else if(data < (root -> data))
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
return root;
}
node *minimum(node *root)
{
	node *temp = root;
	while(temp && temp -> left != NULL)
	temp = temp -> left;
	return temp;
}

node *index(node *root, int val)
{
	if(root!=NULL)
	{
		if(root->data==val)
		{
			cout<<root->p<<endl;
			//return;
		}
		if((root->data)>val)
		{
			index(root->left,val);
		}
		else if((root->data)<val)
		{
			index(root->right,val);
		}
	}
}
node *deleteNode(node *root, int data)
{
	if(root==NULL)
	{
		return root;
	}
	if((root->data)>data)
	{
		root->left=deleteNode(root->left,data);
	}
	else if((root->data)<data)
	{
		root->right=deleteNode(root->right,data);
	}
	else
	{
		if(root->left==NULL)
		{
			node *temp=root->right;
			return temp;
		}
		else if(root->right==NULL)
		{
			node *temp=root->left;
			return temp;
		}
		node *temp = minimum(root -> right);
		root->data=temp->data;
		root->right=deleteNode(root->right,temp->data);
	}
return root;
}

int main()
{
	int total, ele;
	char i;
	node *root = NULL;
	cin>>total;

	while(total--)
	{
		cin>>i;
		cin>>ele;
		if(i == 'i')
		{
			root = insert(root, ele, 1);
		}
		else
		{
			index(root, ele);
			root = deleteNode(root, ele);
		}
	}
return 0;
}

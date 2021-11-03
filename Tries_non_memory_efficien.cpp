//Tries -> it is graph used to store the string
//      -> it is the number of combination of the string
//      -> the only drawback is it have 26 child to evry node 
#include <bits/stdc++.h>
using namespace std;
#define int long long

class trie
{
public:
	struct trie *child[26];
	bool isend;
	trie()
	{
		memset(child, 0, sizeof(child));
		isend = false;
	}
} * root;

void insert(string str)
{
	trie *cur = root;
	for (char c : str)
	{
		int idx = c - 'a';
		if (cur->child[idx] == nullptr)
		{
			cur->child[idx] = new trie;
		}
		cur = cur->child[idx];
	}
	cur->isend = true;
}

bool search(string str)
{
	trie *cur = root;
	for (char c : str)
	{
		int idx = c - 'a';
		if (cur->child[idx] == nullptr)
			return false;
		cur = cur->child[idx];
	}
	return cur->isend;
}

void solve()
{
	root = new trie;
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		insert(s);
	}
	for (int i = 0; i < 3; i++)
	{
		string s;
		cin >> s;
		if (search(s))
			cout << "Yes"
					 << "\n";
		else
			cout << "No"
					 << "\n";
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 1;
	while (T--)
	{
		solve();
	}
	cerr << "[Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << "]\n";
}
#include <bits/stdc++.h>

using namespace std;

vector <string> words;

struct node
{
	bool is_word_end;
	char ch;
	map <char, node*> adj;

	node() {};
};

bool ans = 1;

class trie
{
	public:
		node head;

		trie()
		{ head.ch = -1; }

		void insert(string s)
		{
			node* current_node = &head;
			for (int i = 0; i < s.length(); i++)
			{				
				auto it = (*current_node).adj.find(s[i]);

				if (it != (*current_node).adj.end())
					current_node = it->second;
				else
				{
					node* new_node = new node();
					new_node->ch = s[i];
					(*current_node).adj[s[i]] = new_node;

					current_node = new_node;
				}

				if (i == s.length() - 1)
				{
					current_node->is_word_end = 1;
					if (current_node->adj.size() > 0)
						ans = 0;
				}
			}
		}
};

int main()
{
	ios::sync_with_stdio(false);
	int t, n;
	string temp;

	cin>>t;
	while (t--)
	{
		ans = 1;

		cin>>n;
		trie trie_instance;
		while (n--)
		{
			cin>>temp;
			words.push_back(temp);
		}

		sort(words.begin(), words.end());
		reverse(words.begin(), words.end());

		for (auto x: words)
			trie_instance.insert(x);

		cout<<((ans)?"YES\n":"NO\n");

		words.clear();
	}
	return 0;
}
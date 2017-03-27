#include <bits/stdc++.h>

using namespace std;

#define INF (int)(1e6)
#define pii pair <int, int>

struct compare_keys
{
	bool operator()(const pii &left, const pii &right)
	{
		return left.second > right.second;
	}
};

vector <int> adj[1001];
map <int, map <int, int> > edgew;
int t, p, n, m, min_mst_wgt;
int key[1001], parent[1001];
bool visited[1001];

void reset_graph()
{
	for (int i = 0; i < 1001; i++)
	{
		key[i] = INF;
		parent[i] = -1;
		adj[i].clear();
		visited[i] = 0;
	}
	edgew.clear();
	min_mst_wgt = 0;
}

vector <pii > Q;
void find_min_mst_wgt()
{
	key[1] = 0;
	for (int u = 1; u <= n; u++)
		Q.push_back(make_pair(u, key[u]));
	make_heap(Q.begin(), Q.end(), compare_keys());

	while (!Q.empty())
	{
		int u = Q.front().first;
		pop_heap(Q.begin(), Q.end(), compare_keys());
		Q.pop_back();

		if (!visited[u])
		{
			min_mst_wgt += key[u];
			visited[u] = 1;
		}

		for (auto v: adj[u])
		{
			if (edgew[u][v] < key[v])
			{
				key[v] = edgew[u][v];
				Q.push_back(make_pair(v, key[v]));
				push_heap(Q.begin(), Q.end(), compare_keys());
				parent[v] = u;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--)
	{
		reset_graph();

		cin>>p>>n>>m;
		while (m--)
		{
			int u, v, l;
			cin>>u>>v>>l;
			adj[u].push_back(v), adj[v].push_back(u);
			edgew[u][v] = edgew[v][u] = p*l;
		}

		find_min_mst_wgt();
		cout<<min_mst_wgt<<endl;
	}
	return 0;
}
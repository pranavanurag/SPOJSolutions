#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF (ll)(pow(2, 32))

vector <ll> adj[10001];
map <ll, map <ll, ll> > edgew;
ll n, t, key[10001];
bool visited[10001];

struct compare_keys
{
	bool operator()(const pair <ll, ll> &left, const pair <ll, ll> &right)
	{
		return left.second > right.second;
	}
};

void reset()
{
	for (ll i = 0; i < 10001; i++)
	{
		adj[i].clear();
		key[i] = INF;
		visited[i] = 0;
	}
	edgew.clear();
}

ll find_min_mst_wgt()
{
	ll ans = 0;
	vector <pair <ll, ll> > Q;

	key[1] = 0;
	for (ll i = 1; i <= n; i++)
		Q.push_back(make_pair(i, key[i]));
	make_heap(Q.begin(), Q.end(), compare_keys());

	while (!Q.empty())
	{
		ll u = Q.front().first;
		pop_heap(Q.begin(), Q.end(), compare_keys());
		Q.pop_back();

		if (!visited[u])
		{
			visited[u] = 1;
			// cout<<"u = "<<u<<", key[u] = "<<key[u]<<endl;
			ans += key[u];
		}

		for (auto v: adj[u])
		{
			if (edgew[u][v] < key[v])
			{
				key[v] = edgew[u][v];
				Q.push_back(make_pair(v, key[v]));
				push_heap(Q.begin(), Q.end(), compare_keys());
			}
		}
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--)
	{
		reset();
		cin>>n;
		for (ll u = 1; u <= n; u++)
		{
			string temp;
			ll v, c, m;
			cin>>temp>>m;
			while (m--)
			{
				cin>>v>>c;
				adj[u].push_back(v), adj[v].push_back(u);
				edgew[u][v] = (edgew[u][v])?min(c, edgew[u][v]):c;
				edgew[v][u] = (edgew[v][u])?min(c, edgew[v][u]):c;			
			}
		}
		cout<<find_min_mst_wgt()<<endl;
	}
	return 0;
}
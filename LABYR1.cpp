#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int x[N][N];
int t, n, m;
bool vis[N][N];
int level[N][N];

inline bool can(int i, int j)
{
	if (i < 0 || i > n - 1 || j < 0 || j > m - 1)
		return 0;
	return (x[i][j] && !vis[i][j]);
}

int solve()
{
	memset(vis, 0, sizeof vis);
	pair <int, int> root;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (x[i][j] && !vis[i][j])
			{
				root = make_pair(i, j);
				queue <pair <int, int> > q;
				vis[i][j] = 1;
				q.push(make_pair(i, j));
				while (!q.empty())
				{
					pair <int, int> u = q.front();
					q.pop();

					int ux = u.first, uy = u.second;

					if (can(ux + 1, uy))
						vis[ux + 1][uy] = 1, q.push(make_pair(ux + 1, uy)), root = make_pair(ux + 1, uy);
					if (can(ux - 1, uy))
						vis[ux - 1][uy] = 1, q.push(make_pair(ux - 1, uy)), root = make_pair(ux - 1, uy);
					if (can(ux, uy + 1))
						vis[ux][uy + 1] = 1, q.push(make_pair(ux, uy + 1)), root = make_pair(ux, uy + 1);
					if (can(ux, uy - 1))
						vis[ux][uy - 1] = 1, q.push(make_pair(ux, uy - 1)), root = make_pair(ux, uy - 1);
				}
			}

	memset(vis, 0, sizeof vis);
	memset(level, 0, sizeof level);
	queue <pair <int, int> > q;
	q.push(root);
	vis[root.first][root.second] = 1;
	level[root.first][root.second] = 0;
	int ans = 0;
	while (!q.empty())
	{
		pair <int, int> u = q.front();
		q.pop();

		int ux = u.first, uy = u.second;

		if (can(ux + 1, uy))
			vis[ux + 1][uy] = 1, q.push(make_pair(ux + 1, uy)), level[ux + 1][uy] = level[ux][uy] + 1;
		if (can(ux - 1, uy))
			vis[ux - 1][uy] = 1, q.push(make_pair(ux - 1, uy)), level[ux - 1][uy] = level[ux][uy] + 1;
		if (can(ux, uy + 1))
			vis[ux][uy + 1] = 1, q.push(make_pair(ux, uy + 1)), level[ux][uy + 1] = level[ux][uy] + 1;
		if (can(ux, uy - 1))
			vis[ux][uy - 1] = 1, q.push(make_pair(ux, uy - 1)), level[ux][uy - 1] = level[ux][uy] + 1;
		ans = max(ans, level[ux][uy]);
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>m>>n;
		for (int i = 0; i < n; i++)
		{
			string temp;
			cin>>temp;
			for (int j = 0; j < m; j++)
				x[i][j] = (temp[j] == '.');
		}
		cout<<"Maximum rope length is "<<solve()<<"."<<endl;
	}
	return 0;
}
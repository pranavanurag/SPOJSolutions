#include <bits/stdc++.h>

using namespace std;

#define N (int)(3*1e5 + 1)
#define INF (int)(1e7)
#define scan(x) scanf("%d", &x)

vector <int> tree[4*N];

int a[N], b[N], n;
map <int, vector <int> > my_hash;

int find_next_occ(int arr[], int i)
{
	auto occ = my_hash[arr[i]];
	auto it = lower_bound(occ.begin(), occ.end(), i);
	if (it + 1 != occ.end())
		return *(++it);
	else
		return INF;
}

vector <int> merge(vector <int> left, vector <int> right)
{
	int n1 = left.size(), n2 = right.size();
	int i = 0, j = 0;
	vector <int> ans;
	while (i < n1 && j < n2)
	{
		if (left[i] < right[j])
		{
			ans.push_back(left[i]);
			i++;
		}
		else
		{
			ans.push_back(right[j]);
			j++;
		}
	}
	while (i < n1)
	{
		ans.push_back(left[i]);
		i++;
	}
	while (j < n2)
	{
		ans.push_back(right[j]);
		j++;
	}
	return ans;
}

void build(int i, int stx1, int stx2)
{
	if (stx1 > stx2)
		return;
	else if (stx1 == stx2)
		tree[i].push_back(b[stx1]);
	else
	{
		int stxm = (stx1 + stx2)/2;
		build(2*i, stx1, stxm);
		build(2*i + 1, stxm + 1, stx2);
		auto left = tree[2*i], right = tree[2*i + 1];
		tree[i] = merge(left, right);
	}
}

int query(int i, int stx1, int stx2, int x1, int x2)
{
	if (stx1 > stx2 || x1 > x2 || stx1 > x2 || stx2 < x1)
		return 0;
	else if (stx1 >= x1 && stx2 <= x2)
		return (int)(tree[i].end() - upper_bound(tree[i].begin(), tree[i].end(), x2));
	else
	{
		int stxm = (stx1 + stx2)/2;
		int left = query(2*i, stx1, stxm, x1, x2);
		int right = query(2*i + 1, stxm + 1, stx2, x1, x2);
		return left + right;
	}
}

int main()
{
	scan(n);
	for (int i = 1; i <= n; i++)
	{
		scan(a[i]);
		my_hash[a[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		b[i] = find_next_occ(a, i);

	build(1, 1, n);
	
	int q;
	scan(q);
	while (q--)
	{
		int l, r;
		scan(l), scan(r);
		printf("%d\n", query(1, 1, n, l, r));
	}
	return 0;
}
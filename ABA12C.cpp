#include <iostream>

using namespace std;

int L, P[101], n, Memo[101];

#define INF 1000000

void Refresh()
{
	for (int i = 0; i <= 100; i++)
		Memo[i] = -INF;
}

int DP(int i)
{
	if (Memo[i] >= -1)
		return Memo[i];

	if (i <= 1)
		Memo[i] = P[i];
	else
	{
		Memo[i] = INF;
		for (int j = 1; j <= n; j++)
			if (i >= j && P[j] != -1 && DP(i-j) != -1)
				Memo[i] = min(Memo[i], P[j] + DP(i-j));
		if (Memo[i] == INF)
			Memo[i] = -1;
	}

	return Memo[i];
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--)
	{
		Refresh();

		cin>>L>>n;
		for (int i = 1; i <= n; i++)
			cin>>P[i];

		cout<<DP(n)<<endl;
	}
	return 0;
}
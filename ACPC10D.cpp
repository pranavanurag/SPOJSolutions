#include <bits/stdc++.h>

using namespace std;

#define INF (int)(1e9)

int a[100001][4], n, memo[100001][4];

void refresh_memo()
{
	for (int i = 0; i <= (int)(1e5); i++)
		for (int j = 0; j <= 3; j++)
			memo[i][j] = INF;
}

int dp(int i, int j)
{
	if (i < 1 || j < 1 || i > n || j > 3)
		return INF;
	else if (i == n && j == 2)
		return a[i][j];
	else if (i == n && j == 3)
		return INF;
	else if (memo[i][j] != INF)
		return memo[i][j];
	else
	{
		memo[i][j] = a[i][j] + min(dp(i + 1, j),
									min(dp(i, j + 1),
										min(dp(i + 1, j + 1), dp(i + 1, j - 1))));
		// cout<<"memo["<<i<<"]["<<j<<"] = "<<memo[i][j]<<endl;
		return memo[i][j];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int t = 0;
	while (cin>>n && n != 0)
	{
		t++;
		cout<<t<<". ";
		refresh_memo();

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin>>a[i][j];

		cout<<dp(1, 2)<<endl;
	}
	return 0;
}
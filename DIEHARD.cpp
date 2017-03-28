#include <iostream>

using namespace std;

int health, armor;
int memo[2001][2001][4];

void refresh_memo()
{
	for (int i = 0; i <= 2000; i++)
		for (int j = 0; j <= 2000; j++)
			for (int k = 0; k <= 3; k++)
				memo[i][j][k] = -1;
}

int dp(int h, int a, int c)
{
	if (h <= 0 || a <= 0)
		return 0;
	else if (memo[h][a][c] != -1)
		return memo[h][a][c];
	else
	{
		if (c == 1)
			memo[h][a][c] = 1 + max(dp(h - 5, a - 10, 2), dp(h - 20, a + 5, 3));
		else if (c == 2)
			memo[h][a][c] = 1 + max(dp(h + 3, a + 2, 1), dp(h - 20, a + 5, 3));
		else
			memo[h][a][c] = 1 + max(dp(h - 5, a - 10, 2), dp(h + 3, a + 2, 1));
		return memo[h][a][c];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--)
	{
		cin>>health>>armor;
		refresh_memo();
		cout<<max(dp(health + 3, armor + 2, 1), 
				max(dp(health - 5, armor - 10, 2), 
					dp(health - 20, armor + 5, 3)))<<endl;
	}
	return 0;
}
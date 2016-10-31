#include <bits/stdc++.h>

using namespace std;

int Memo[1000001];

int main()
{
	ios::sync_with_stdio(false);
	int K, L, m;
	cin>>K>>L>>m;
	for (int i = 1; i <= m; i++)
	{
		int N;
		cin>>N;

		memset(Memo, 1, sizeof(Memo));
		Memo[0] = 0;
		for (int n = 1; n <= N; n++)
		{
			if (n >= L)
			{
				if (Memo[n - L] && Memo[n - K] && Memo[n - 1])
					Memo[n] = 0;
			}
			else if (n >= K)
			{
				if (Memo[n - K] && Memo[n - 1])
					Memo[n] = 0;
			}
			else
			{
				if (Memo[n - 1])
					Memo[n] = 0;
			}
		}
		(Memo[N])?cout<<'A':cout<<'B';
	}
	cout<<endl;
	return 0;
}
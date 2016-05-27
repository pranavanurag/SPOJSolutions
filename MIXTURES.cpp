#include <iostream>

using namespace std;

int C[101], Memo[101][101], n;

void Refresh()
{
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			Memo[i][j] = -1;
}

int Smoke(int i, int k, int j)
{
	int a = 0, b = 0;

	for (int x = i; x <= k; x++)
		a += C[x];
	for (int x = k+1; x <= j; x++)
		b += C[x];

	a = a%100;
	b = b%100;

	return a*b;
}

int DP(int i, int j)
{
	if (Memo[i][j] >= 0)
		return Memo[i][j];

	if (j == i)
		Memo[i][j] = 0;

	else
	{
		Memo[i][j] = 1000001;
		for (int k = i; k <= j-1; k++)
			Memo[i][j] = min(Memo[i][j], DP(i, k) + DP(k+1, j) + Smoke(i, k, j));
	}

	return Memo[i][j];
}

int main()
{
	ios::sync_with_stdio(false);

	while (cin>>n)
	{
		Refresh();
		for (int i = 1; i <= n; i++)
			cin>>C[i];

		cout<<DP(1, n)<<endl;
	}
	return 0;
}
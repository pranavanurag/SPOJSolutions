#include <iostream>

using namespace std;

int main()
{
	int S, N;
	cin>>S>>N;
	int Cost[N+1], Value[N+1];
	for (int i = 1; i <= N; i++)
		cin>>Cost[i]>>Value[i];

	int DP[S+1][N+1];
	for (int i = 0; i <= S; i++)
		DP[i][0] = 0;

	for (int i = 1; i <= N; i++)
		for (int x = 0; x <= S; x++)
			if (x >= Cost[i])
				DP[x][i] = max(DP[x][i-1], DP[x-Cost[i]][i-1] + Value[i]);
			else
				DP[x][i] = DP[x][i-1];

	cout<<DP[S][N]<<endl;
	return 0;
}

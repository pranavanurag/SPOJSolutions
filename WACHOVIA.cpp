#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int K, M;
		cin>>K>>M;
		int Weight[M+1], Value[M+1];
		for (int i = 1; i <= M; i++)
			cin>>Weight[i]>>Value[i];

		int DP[K+1][M+1];
		for (int i = 0; i <= K; i++)
			DP[i][0] = 0;

		for (int i = 1; i <= M; i++)
			for (int x = 0; x <= K; x++)
				if (x >= Weight[i])
					DP[x][i] = max(DP[x][i-1], DP[x-Weight[i]][i-1] + Value[i]);
				else
					DP[x][i] = DP[x][i-1];

		cout<<"Hey stupid robber, you can get "<<DP[K][M]<<"."<<endl;
	}
	return 0;
}

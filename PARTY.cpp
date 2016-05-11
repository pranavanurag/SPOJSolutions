#include <iostream>

using namespace std;

int main()
{
	int Budget, N;
	while (cin>>Budget && cin>>N && !(Budget == 0 && N == 0))
	{
		int Fun[N+1], Cost[N+1];
		for (int i = 1; i <= N; i++)
			cin>>Cost[i]>>Fun[i];

		int DP[Budget+1][N+1];

		for (int i = 0; i <= Budget; i++)
			DP[i][0] = 0;

		for (int i = 1; i <= N; i++)
			for (int x = 0; x <= Budget; x++)
				if (x >= Cost[i])
					DP[x][i] = max(DP[x][i-1], DP[x-Cost[i]][i-1] + Fun[i]);
				else
					DP[x][i] = DP[x][i-1];

		int MaxFun = DP[Budget][N];
		int MinBudget;
		for (int i = 0; i <= Budget; i++)
			for (int j = 1; j <= N; j++)
				if (DP[i][j] == MaxFun)
				{
					MinBudget = i;
					goto l;
				}

		l:
			cout<<MinBudget<<' '<<MaxFun<<endl;			
	}
	return 0;
}

/*input
3

10 110
2
1 1
30 50

10 110
2
1 1
50 30

1 6
2
10 3
20 4
*/
#include <iostream>

using namespace std;

int T, E, F, N, TW, P[501], W[501];
int Memo[10001][10001];

#define MAX 1000000;

int main()
{
	ios::sync_with_stdio(false);
	
	cin>>T;
	while (T--)
	{
		cin>>E>>F>>N;
		TW = F - E;
		for (int i = 1; i <= N; i++)	//following 1-based indexing
			cin>>P[i]>>W[i];

		for (int i = 1; i <= N; i++)
			for (int x = 0; x <= TW; x++)
				Memo[i][x] = 0;

		for (int x = 0; x <= TW; x++)
			Memo[0][x] = 0;

		for (int i = 1; i <= N; i++)
			for (int x = 0; x <= TW; x++)
				for (int k = 0; k <= (int)(TW/W[i]); k++)
					if (x >= k*W[i])
						Memo[i][x] = max(Memo[i-1][x-k*W[i]] + k*P[i], Memo[i][x]);
					else
						Memo[i][x] = Memo[i-1][x];

		int ans = MAX;

		for (int i = 1; i <= N; i++)
			cout<<Memo[i][0]<<' ';
		cout<<endl;
		cout<<"TW "<<TW<<" N "<<N<<endl;
		cout<<ans<<endl<<endl;
	}
	return 0;
}
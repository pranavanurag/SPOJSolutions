#include <iostream>

using namespace std;

int Memo[6101][6101];

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--)
	{
		for (int i = 0; i < 6101; i++)
			for (int j = 0; j < 6101; j++)
				Memo[i][j] = 0;
		string S;
		cin>>S;
		int n = S.size();
		for (int i = n-1; i >= 0 ; i--)
			for (int j = 0; j <= n-1; j++)
				if (i == j)
					Memo[i][j] = 0;
				else if (S[i] == S[j])
					Memo[i][j] = Memo[i+1][j-1];
				else
					Memo[i][j] = min(Memo[i+1][j], Memo[i][j-1])+1;
		cout<<Memo[0][n-1]<<endl;
	}
	return 0;
}
/*input
2
tff
pranav
*/
#include <iostream>
#include <string>

using namespace std;

const int N = 6500;

int Memo[N][N];

void RefreshMemo()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Memo[i][j] = -1;
}

int MinPalin(string x, int i, int j)
{
	if (Memo[i][j] >= 0)
		return Memo[i][j];

	else if (i == j)	//base case
	{
		Memo[i][j] = 0;
		return Memo[i][j];
	}

	else
	{
		//write recurrence here
		for (int k = i+1; k < j; k++)
			Memo[i][j] = min(MinPalin(x, i+1, k), MinPalin(x, k+1, j)) + 1;
		return Memo[i][j];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--)
	{
		string S;
		cin>>S;
		RefreshMemo();
		cout<<MinPalin(S, 1, S.size())<<endl;
	}
}

#include <iostream>

using namespace std;

int Memo[100001], P[500001], W[10001], N;

void Refresh()
{
	for (int i = 0; i < 100001; i++)
		Memo[i] = -1;
}

int DP(int L)
{
	if (Memo[L] >= 0)
		return Memo[L];

	if (L == 0)
		Memo[L] = 0;
	else
	{
		Memo[L] = 9999999;
		for (int i = 1; i <= N; i++)
			if (W[i] <= L)
				Memo[L] = min(Memo[L], DP(L-W[i]) + P[i]);
	}

	return Memo[L];
}

int main()
{
	ios::sync_with_stdio(false);
	
	int t;
	cin>>t;
	while (t--)
	{
		Refresh();

		int E, F;
		cin>>E>>F>>N;

		for (int i = 1; i <= N; i++)
			cin>>P[i]>>W[i];

		if (DP(F-E) != 9999999)
			cout<<"The minimum amount of money in the piggy-bank is "<<DP(F-E)<<"."<<endl;
		else
			cout<<"This is impossible."<<endl;
	}
	return 0;
}
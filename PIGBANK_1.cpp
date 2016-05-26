#include <iostream>

using namespace std;

int Memo[100001], P[500001], W[10001], N;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin>>t;

	while (t--)
	{
		int E, F;
		cin>>E>>F>>N;

		for (int i = 1; i <= N; i++)
			cin>>P[i]>>W[i];

		for (int l = 1; l <= F-E; l++)
		{
			Memo[l] = 9999999;
			for (int i = 1; i <= N; i++)
				if (W[i] <= l)
					Memo[l] = min(Memo[l], Memo[l-W[i]] + P[i]);
		}

		if (Memo[F-E] != 9999999)
			cout<<"The minimum amount of money in the piggy-bank is "<<Memo[F-E]<<"."<<endl;
		else
			cout<<"This is impossible."<<endl;
	}
	
	return 0;
}
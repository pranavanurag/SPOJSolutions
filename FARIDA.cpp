#include <iostream>

using namespace std;

long long N, A[10001], Memo[10001];

int main()
{
	ios::sync_with_stdio(false);

	Memo[0] = 0;

	int t;
	cin>>t;
	for (int c = 1; c <= t; c++)
	{
		cin>>N;
		for (int i = 1; i <= N; i++)
			cin>>A[i];

		for (int i = 1; i <= N; i++)
			if (i == 1)
				Memo[i] = A[i];
			else
				Memo[i] = max(Memo[i-1], Memo[i-2] + A[i]);

		cout<<"Case "<<c<<": "<<Memo[N]<<endl;
	}
	return 0;
}
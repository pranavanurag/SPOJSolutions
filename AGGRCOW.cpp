#include <bits/stdc++.h>

using namespace std;

int N, A[1000001], T, C;

bool Predicate(int MinDist)
{
	int Placed = 1, LastPlacedAt = A[1];
	for (int i = 2; i <= N && Placed < C; i++)
	{
		if (A[i] - LastPlacedAt >= MinDist)
		{
			LastPlacedAt = A[i];
			Placed++;
		}
	}
	return (Placed == C);
}

int BinSearch(int Low, int High)
{
	int Mid = Low + (High - Low + 1)/2;
	while (Low < High)
	{
		if (Predicate(Mid))
			Low = Mid;
		else
			High = Mid - 1;
		Mid = Low + (High - Low + 1)/2;
	}
	return High;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--)
	{
		cin>>N>>C;
		for (int i = 1; i <= N; i++)
			cin>>A[i];
		sort(A + 1, A + N + 1);
		cout<<BinSearch(1, A[N])<<endl;
	}
	return 0;
}
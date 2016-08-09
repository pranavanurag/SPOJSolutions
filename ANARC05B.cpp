#include <bits/stdc++.h>

using namespace std;

int N1, N2, A[100001], B[100001];

int Solve()
{
	int Ans = 0;
	A[0] = B[0] = 0;

	vector <int> One, Two;
	
	One.push_back(0);
	Two.push_back(0);
	for (int i = 1; i <= N1; i++)
		if (binary_search(B+1, B+N2+1, A[i]))
			One.push_back(i);
	for (int i = 1; i <= N2; i++)
		if (binary_search(A+1, A+N1+1, B[i]))
			Two.push_back(i);

	for (int i = 1; i < One.size(); i++)
	{
		int GainA = 0, GainB = 0;
		for (int j = One[i-1]; j < One[i]; j++)
			GainA += A[j];
		for (int j = Two[i-1]; j < Two[i]; j++)
			GainB += B[j];
		Ans += max(GainA, GainB);
	}

	int GainA = 0, GainB = 0;
	for (int j = One[One.size()-1]; j <= N1; j++)
		GainA += A[j];
	for (int j = Two[Two.size()-1]; j <= N2; j++)
		GainB += B[j];

	Ans += max(GainA, GainB);

	return Ans;
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin>>N1 && N1 != 0)
	{
		for (int i = 1; i <= N1; i++)
			cin>>A[i];
		cin>>N2;
		for (int i = 1; i <= N2; i++)
			cin>>B[i];

		cout<<Solve()<<endl;
	}
	return 0;
}
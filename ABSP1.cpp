#include <bits/stdc++.h>

using namespace std;

int A[10001], T, N;

int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--)
	{
		long long Ans = 0;
		cin>>N;
		for (int i = 1; i <= N; i++)
			cin>>A[i];
		for (int i = N; i >= 1; i--)
			Ans += -(N + 1 - 2*i)*A[i];
		cout<<Ans<<endl;
	}
	return 0;
}
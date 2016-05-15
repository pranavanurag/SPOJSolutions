#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--)
	{
		int k, n;
		cin>>n>>k;
		long A[n];
		for (int i = 0; i < n; i++)
			cin>>A[i];
		sort(A, A+n);
		long ans = 1000000000;
		for (int i = 0; i < n-k+1; i++)
			if (A[k-1+i] - A[i] < ans)
				ans = A[k-1+i] - A[i];
		if (k == n)
			ans = A[n-1] - A[0];
		cout<<ans<<endl;
	}
	return 0;
}

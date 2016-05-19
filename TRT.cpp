#include <iostream>

using namespace std;

int Memo[2010][2010], A[2010];

int DP(int i, int j, int a)
{
	if (Memo[i][j])
		return Memo[i][j];
	
	else if (i == j)
	{
		Memo[i][j] = A[i]*a;
		return Memo[i][j];
	}
	
	else
	{
		Memo[i][j] = max(DP(i+1, j, a+1) + A[i]*a, DP(i, j-1, a+1) + A[j]*a);
		return Memo[i][j];
	}
}

int main()
{
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>A[i];
	cout<<DP(1, n, 1)<<endl;
	return 0;
}

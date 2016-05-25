#include <iostream>

using namespace std;

int Memo[6000][6000];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;

	char x[n];
	cin>>x;
	
	for (int i = n-1; i >= 0 ; i--)
	for (int j = 0; j <= n-1; j++)
		if (i == j)
			Memo[i][j] = 0;
		else if (x[i] == x[j])
			Memo[i][j] = Memo[i+1][j-1];
		else
			Memo[i][j] = min(Memo[i+1][j], Memo[i][j-1])+1;

	cout<<Memo[0][n-1]<<endl;
return 0;
}

/*input
1
tff
*/
#include <iostream>
#include <string>

using namespace std;

int Memo[6100][6100];
string x;

void RefreshMemo()
{
	for (int i = 0; i < 6100; i++)
		for (int j = 0; j < 6100; j++)
			Memo[i][j] = -1;
}

bool IsPalin(string x)
{
	for (int i = 0; i < x.size(); i++)
		if (x[i] != x[x.size()-i-1])
			return 0;
	return 1;
}

int MinPalin(int i, int j)
{
	if (Memo[i][j] >= 0)
		return Memo[i][j];

	else
	{
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while (n--)
	{
		cin>>x;

	}
}

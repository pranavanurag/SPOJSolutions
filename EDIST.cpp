#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string x, y;
		cin>>x>>y;
		int n1 = x.length();
		int n2 = y.length();
		vector<vector<int> > Memo(n1 + 1, vector<int>(n2 + 1));

		for(int i = n1; i >= 0; i--)
			for(int j = n2; j >= 0; j--)
			{
				if(n1-i == 0)
					Memo[i][j] = n2-j;
				else if(n2-j == 0)
					Memo[i][j] = n1-i;
				else if(x[i] == y[j])
					Memo[i][j] = Memo[i+1][j+1];
				else
					Memo[i][j] = min(min(Memo[i+1][j+1], Memo[i][j+1]), Memo[i+1][j]) + 1;
			}

		cout<<Memo[0][0]<<endl;	
	}
	return 0;
}

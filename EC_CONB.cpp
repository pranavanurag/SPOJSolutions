#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int T, A;
	cin>>T;
	while (T--)
	{
		cin>>A;
		if (A%2 == 0)
		{
			int Ans = 0;
			vector <int> B;
			while (A > 1)
			{
				B.push_back(A%2);
				A = A/2;
			}
			B.push_back(A%2);
			for (int i = 0; i < B.size(); i++)
				Ans = 2*Ans + B[i];
				cout<<Ans<<endl;
		}
		else
			cout<<A<<endl;
	}
	return 0;
}
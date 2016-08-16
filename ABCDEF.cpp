#include <bits/stdc++.h>

using namespace std;

int N, S[101];
vector <int> ABC, DEF;

int main()
{
	ios::sync_with_stdio(false);
	cin>>N;
	for (int i = 1; i <= N; i++)
		cin>>S[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
			{
				int A = S[i], B = S[j], C = S[k];
				ABC.push_back(A*B + C);
			}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
			{
				int D = S[i], E = S[j], F = S[k];
				if (D != 0)
					DEF.push_back((F + E)*D);
			}

	sort(ABC.begin(), ABC.end());
	sort(DEF.begin(), DEF.end());

	unsigned long long Ans = 0;
	for (int i = 0; i < ABC.size(); i++)
		if (binary_search(DEF.begin(), DEF.end(), ABC[i]))
			Ans += distance(lower_bound(DEF.begin(), DEF.end(), ABC[i]), upper_bound(DEF.begin(), DEF.end(), ABC[i]));

	cout<<Ans<<endl;
	return 0;
}
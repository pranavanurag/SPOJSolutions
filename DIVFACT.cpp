#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007
#define ll long long

int T, N;
bool IsPrime[1000001];

void Seive()
{
	for (int i = 1; i <= 1000000; i++)
		IsPrime[i] = 1;
	for (int i = 2; i <= 1000; i++)
		if (IsPrime[i])
			for (int j = i*i; j <= 1000000; j += i)
				IsPrime[j] = 0;
	IsPrime[0] = IsPrime[1] = 0;
}

ll NumberOfFactors(int N)
{
	vector <int> PrimePowers;
	for (int i = 2; i <= N; i++)
		if (IsPrime[i])
		{
			int PP = 0, N1 = N;
			while (N1 > 0)
			{
				PP += N1/i;
				N1 /= i;
			}
			// cout<<i<<", "<<PP<<endl;
			PrimePowers.push_back(PP);
		}
	ll Ans = 1;
	for (int i = 0; i < PrimePowers.size(); i++)
		Ans = (Ans%MOD * (PrimePowers[i] + 1)%MOD)%MOD;
	return Ans%MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	Seive();
	cin>>T;
	while (T--)
	{
		cin>>N;
		cout<<NumberOfFactors(N)<<endl;
	}
	return 0;
}
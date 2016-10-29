#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll Pre(ll x)
{
	return (x*(x + 1)/2)%MOD;
}

ll SUMPRO(ll N)
{
	ll Ans = 0;
	ll SN = sqrt(N);
	for (ll i = 1; i <= SN; i++)
	{
		if (i != (N/i))
			Ans += (i*(Pre(N/i) - Pre(N/(i + 1))))%MOD + ((N/i)*i)%MOD;
		else
			Ans += i*(N/i);
	}
	return Ans%MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	int T, N;
	cin>>T;
	while (T--)
	{
		cin>>N;
		cout<<SUMPRO(N)<<endl;
	}
	return 0;
}
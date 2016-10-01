y#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

map <int, ull> Memo;

ull DP(ull n)
{
	if (n < 12)
		return n;
	if (Memo.count(n))
		return Memo[n];
	Memo[n] = max(DP(n/2) + DP(n/3) + DP(n/4), n);
	return Memo[n];
}

int main()
{
	ios::sync_with_stdio(false)
	ull x;
	while (cin>>x)
		cout<<DP(x)<<endl;	
	return 0;
}

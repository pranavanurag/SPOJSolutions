#include <iostream>

using namespace std;

#define ull unsigned long long

ull GCD(ull x, ull y)
{
	ull a = max(x, y), b = min(x, y);
	if (b == 0)
		return a;
	if (a%b == 0)
		return b;
	return GCD(a%b, b);
}

int main()
{
	ios::sync_with_stdio(false);
	ull w, h;
	while (cin>>w>>h && w != 0 && h != 0)
		cout<<(h*w)/(GCD(h, w)*GCD(h, w))<<endl;
	return 0;
}
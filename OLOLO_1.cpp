#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	long long x;
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>x;
		ans = ans^x;
	}
	cout<<ans;
	return 0;
}

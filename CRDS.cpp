#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		unsigned long long N;
		cin>>N;
		cout<<((N + 1)*(N) + ((N)*(N - 1)/2))%1000007<<endl;
	}
	return 0;
}
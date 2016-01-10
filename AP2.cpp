#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	long long Sum, Third, ThirdLast;

	while(t--&&t>=0)
	{
		cin>>Third>>ThirdLast>>Sum;

		long long n = ((2*Sum)/(ThirdLast + Third));
		cout<<n<<endl;

		long long d = (ThirdLast - Third)/(n - 5);

		long long a = Third - 2*d;

		for(int i = 1; i <= n; i++)
			cout<<(a + (i-1)*d)<<' ';

		cout<<endl;
	}
	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	int t;
	unsigned long long n;
	cin>>t;
	while(t--&&t>=0)
	{
		cin>>n;
		cout<<192+250*(n-1)<<endl;
	}
}
#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		unsigned long long x;
		cin>>x;
		cout<<"Case "<<i+1<<": "<<(4*x*x)<<".25"<<endl;
	}
	return 0;
}
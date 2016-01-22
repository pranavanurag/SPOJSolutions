#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t-- && t >= 0)
	{
		unsigned long long int x;
		cin>>x;
		cout<<((2*x+1)*(x)*(x+2))/8<<endl;
	}
	return 0;
}
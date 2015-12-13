#include <iostream>

using namespace std;

int main()
{
	unsigned long long int n=1;
	while(n!=0)
	{
		cin>>n;
		cout<<(n*(n+1)*(2*n+1)/6);
	}
}
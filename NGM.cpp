#include <iostream>

using namespace std;

int main()
{
	unsigned long long int n;
	cin>>n;
	if(n%10 != 0)
		cout<<1<<endl<<n%10;
	else
		cout<<2;
	return 0;
}
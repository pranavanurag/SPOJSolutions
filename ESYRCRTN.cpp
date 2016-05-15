#include <iostream>

using namespace std;

long long int F(long long int n)
{
	switch(n%6)
	{
		case 0:	return -2;
				break;
		case 1: return 1;
				break;
		case 2: return 3;
				break;
		case 3: return 2;
				break;
		case 4: return -1;
				break;
		case 5: return -3;
				break;
	}
}

int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		long long int x;
		cin>>x;
		if (x == 1)
			cout<<1<<endl;
		else if (x == 2)
			cout<<4<<endl;
		else
			cout<<F(x-1)+3<<endl;
	}
	return 0;
}

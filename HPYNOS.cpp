/*input
132435243254
*/
#include <iostream>

using namespace std;

long Break(long x)
{
	long a = 0;
	while(x > 0)
	{
		a += (x%10)*(x%10);
		x /= 10;
	}
	return a;
}

int isHappy(long x)
{
	if(x == 1)
		return 0;
	int c = 0;
	do
	{	
		x = Break(x);
		if(x == 37)
			return -1;		
		c++;
	}while(x != 1);

	return c;
}

int main()
{
	ios::sync_with_stdio(false);
	long x;
	cin>>x;
	cout<<isHappy(x);
	return 0;
}
#include <iostream>

using namespace std;

inline int Max(int x, int y)
{
   return (x > y)? x : y;
}


int main()
{
	int g, b;
	while(cin>>g && cin>>b && (g+b) != -2)
	{
		if(g==0 && b==0)
			cout<<0<<endl;
		else if(g == b)
			cout<<1<<endl;
		else
		{
			int n = Max(g, b);
			int gaps = g + b - n + 1;
			//now place 'n' identical items in 'gaps' places
			if(n%gaps)
				cout<<(n/gaps) + 1<<endl;
			else
				cout<<n/gaps<<endl;
		}
	}
	return 0;
}
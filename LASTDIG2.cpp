#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string x;
		long long b;
		cin>>x>>b;
		int a = int(x[x.length() - 1] - '0');

		if(b==0)
			cout<<1<<endl;
		else
		{
			if(a==0||a==1||a==5||a==6) 
				cout<<a<<endl;
			else if(a==2||a==3||a==7||a==8) 
				cout<<(int)(pow(a,b%4+4))%10<<endl;
			else if(a==4||a==9)
				cout<<(int)(pow(a,b%2+2))%10<<endl;
		}
	}
	return 0;
}

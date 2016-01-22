#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int t,a;
	long b;
	cin>>t;
	while(t--&&t>=0)
	{
		cin>>a>>b;
		a=a%10;
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
#include <iostream>

using namespace std;

int main()
{
	long t;
	cin>>t;
	int x, y;

	for(long i=0;i<t;i++)
	{
		cin>>x>>y;
		if(x==y||x==y+2)
		{
			if(x%2==0&&y%2==0) cout<<x+y<<endl;
			else cout<<x+y-1<<endl;
		}
		else cout<<"No Number"<<endl;
	}
	return 0;
}
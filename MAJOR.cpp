#include <iostream>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	
	while (t--)
	{
		int n, data;
		cin>>n;
		
		int f[1000001] = {0};
		for (int i = 0; i < n; i++)
		{
			cin>>data;
			//cout<<data<<' ';
			f[data+1000]++;
		}
		
		bool flag = true;
		for (int i = 0; i < 1000001; i++)
			if (f[i] > n/2)
			{
				cout<<"YES "<<i-1000<<endl<<endl;
				flag = false;
				break;
			}
		if (flag)
			cout<<"NO"<<endl<<endl;
	}
}

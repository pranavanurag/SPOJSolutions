#include <iostream>

using namespace std;

int main()

{
	unsigned long long int total=0, n, NumberOfCandies;
	int t;
	cin>>t;
	while(t--&&t>=0)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{	
			cin>>NumberOfCandies;
			total=total%n + NumberOfCandies%n;
		}
			
		if(total%n==0)	cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		total=0;
	}
	return 0;
}
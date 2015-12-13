#include <iostream>

using namespace std;

int main()
{
	float n, sum;
	while(cin>>n&&n!=0.00)
	{
		sum=0;
		float i=1;
		while(sum<n&&i++)
			sum+=1/i;
		cout<<i-1<<" card(s)"<<endl;
	}
	return 0;
}
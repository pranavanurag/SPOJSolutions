#include <iostream>

using namespace std;

long Answer(long x[], long c)	//function to calculate optimum solution for given stall positions and number of cows
{
	
}

int main()
{
	int t;	//number of test cases
	long StallPositions[1000000];	//array containing positions of 'n' stalls
	long c, n;	//c = number of cows, n = number of stalls

	cin>>t;

	while(t-- && t >= 0)
	{
		cin>>n>>c;
		for(int i = 0;i < n; i++)
			cin>>StallPositions[i];
		cout<<Answer(StallPositions, c);
	}
}
#include <iostream>
#include <math.h>

using namespace std;

int NumberOfFactors(int n)
{
	int c=0;
	for(int i=1;i<=sqrt(n);i++)
		if(n%i==0) c++;
	return c;
}

int main()
{
	int n;
	cin>>n;
	long answer=0;
	for(int i=1;i<=n;i++)
		answer+=NumberOfFactors(i);
	cout<<answer;
	return 0;
}
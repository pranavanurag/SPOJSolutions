#include <iostream>
using namespace std;

long long TrailingZeroes(long long x)	//funtion to divide the argument by 5 repeatedly and count the number of times it survvies
{
	long long n=0;
	while(x>0)
	{
		n+=x/5;
		x/=5;
	}
	return n;
}

int main() {
	long t;
	long long x;
	
	cin>>t;	//number of test cases
	
	for(long i=0;i<t;i++)
	{
		cin>>x;
		cout<<TrailingZeroes(x)<<endl;	//output
	}
	return 0;
}
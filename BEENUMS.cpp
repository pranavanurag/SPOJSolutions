#include <iostream>
#include <math.h>

using namespace std;

bool IsPerfectSquare(long x)
{
	double root = sqrt(x);
	double longlongpart;
	double fraction = modf(root, &longlongpart);
	return (fraction == 0);
}

int main()
{
	long long x;
	cin>>x;
	while(x!=-1)
	{
		if(IsPerfectSquare(4*x-1))
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
		cin>>x;
	}
	return 0;
}
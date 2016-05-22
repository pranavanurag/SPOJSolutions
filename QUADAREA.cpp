 #include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double MaxArea(double a, double b, double c, double d)
{
	double s = (a + b + c + d)/2;
	return sqrt((s-a)*(s-b)*(s-c)*(s-d));
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	cout<<fixed<<setprecision(2);
	while (t--)
	{
		double a, b, c, d;
		cin>>a>>b>>c>>d;
		cout<<MaxArea(a, b, c, d)<<endl;
	}
	return 0;
}

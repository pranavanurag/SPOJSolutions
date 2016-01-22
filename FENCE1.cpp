#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x;
	int t;
	while(cin>>x && x != 0)
		cout<<fixed<<setprecision(2)<<((x*x)/(2*3.14159))<<endl;
	return 0;
}
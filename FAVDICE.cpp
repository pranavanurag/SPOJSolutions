#include <iostream>
#include <iomanip>

using namespace std;

float f(int n)
{
	float sum = 0;
	for (float i = 1; i <= n; i++)
		sum += (1/i);
	return sum;
}

float roundoff(float n)
{
	float x = n*100;
	x = (int)(x+0.5);
	return x/100;
}

int main()
{
	int t;
	cin>>t;
	cout<<fixed;
	cout<<setprecision(2);
	while (t--)
	{
		float n;
		cin>>n;
		n *= f(n);
		cout<<roundoff(n)<<endl;
	}
}

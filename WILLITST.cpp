#include <iostream>

using namespace std;

int integer(double Value)
{
	double intpart;
	modf(Value, &intpart);
	if(Value==intpart) return 1;
	else return 0;
}

int main()
{
	unsigned long long n;
	cin>>n;
	if(integer(log2(n))) cout<<"TAK";
	else cout<<"NIE";
	return 0;
}
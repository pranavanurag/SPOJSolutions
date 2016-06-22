#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	string x;
	while (cin>>x)
	{
		if (x == "00e0")
			break;
		int n = (10*(int)(x[0] - '0') + (int)(x[1] - '0'))*pow(10, (int)(x[3] - '0'));
		cout<<2*(int)(n - pow(2, (int)log2(n)))+1<<endl;
	}
	return 0;
}
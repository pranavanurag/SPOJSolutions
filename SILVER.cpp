#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	float n;
	while (cin>>n && n != 0)
		cout<<(int)( ( sqrt(8*n) - 1)/2 - 0.5)<<endl;
	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		string P, T;
		cin>>P>>T;

		int N = T.size();
		int M = P.size();

		bool notFound = true;

		for (int i = 0; i < N-M+1; i++)
			if (T.substr(i, M) == P)
			{
				notFound = false;
				cout<<i<<endl;
			}

		if (notFound)
			cout<<endl;
	}
	return 0;
}
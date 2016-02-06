#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{	
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	long long Pyanis[n];
	for(int i = 0; i < n; i++)
		cin>>Pyanis[i];
	sort(Pyanis, Pyanis + n);
	int i = 0;
	while(i < n)
	{
		if(Pyanis[i] == Pyanis[i+1])
			i += 2;
		else
		{
			cout<<Pyanis[i];
			break;
		}
	}
	return 0;
}

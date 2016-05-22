#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline int mod(int x)
{
	if (x < 0)
		return -x;
	return x;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	
	while (t--)
	{
		
		int n1, n2, input;
		cin>>n1;
		vector<int> v1;
		for (int i = 0; i < n1 && cin>>input; i++)
			v1.push_back(input);

		cin>>n2;
		vector<int> v2;
		for (int i = 0; i < n2 && cin>>input; i++)
			v2.push_back(input);

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		int ans = 10000000;
		for (int i = 0; i < n1; i++)
		{
			int pos = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();

			if (pos == n2)
				pos--;

			if (pos >= 1 && pos <= n2-2)
				ans = min(ans, min(mod(v2[pos] - v1[i]), min(mod(v2[pos+1] - v1[i]), mod(v2[pos-1] - v1[i]))));
			else if (pos >= 1)
				ans = min(ans, min(mod(v2[pos] - v1[i]), mod(v2[pos-1] - v1[i])));
			else if (pos <= n2-2)
				ans = min(ans, min(mod(v2[pos] - v1[i]), mod(v2[pos+1] - v1[i])));
			else
				ans = min(ans, mod(v2[pos] - v1[i]));
			
			//cout<<"Finding closest element to "<<v1[i]<<". Found "<<v2[pos]<<" at "<<pos<<". Answer updated to "<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}

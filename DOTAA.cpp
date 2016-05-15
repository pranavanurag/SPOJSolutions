#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--)
	{
		int n, m, D;
		cin>>n>>m>>D;
		int H[n];
		for (int i = 0; i < n; i++)
			cin>>H[i];

		sort(H, H+n);
		reverse(H, H+n);

		bool CanCross = true;
		int TowersSurvived = 0;
		int i = 0;
		while (TowersSurvived < m)
		{
			if (H[i] > D)
			{
				H[i] = H[i] - D;
				TowersSurvived++;
			}
			else if (H[i+1] > D)
				i++;
			else
			{
				CanCross = false;
				break;
			}
		}

		if (CanCross)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

string Accounts[1000000];

void ShowAccount(string x)
{
	for (int i = 0; i < 26; i++)
	{
		cout<<x[i];
		if (i == 1 || i == 9 || i == 13 || i == 17 || i == 21 || i == 26)
			cout<<" ";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	string cd, bc, o1, o2, o3, o4;
	while (t--)
	{
		int n;
		cin>>n;
		for (int i = 0; i < n; i++)
		{
			cin>>cd>>bc>>o1>>o2>>o3>>o4;
			Accounts[i] = cd + bc + o1 + o2 + o3 + o4;
		}

		sort(Accounts, Accounts + n);

		for (int i = 0; i < n;)
		{
			int freq = 1;
			for (int j = i+1; j < n; j++)
				if (Accounts[j] != Accounts[i])
					break;
				else
					freq++;
			ShowAccount(Accounts[i]);
			cout<<" "<<freq<<endl;
			i = i + freq;
		}
		cout<<endl;
	}
	return 0;
}
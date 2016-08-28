#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, temp;
	cin>>N;

	vector<int> Friends, Temp, FoF;

	for (int i = 1; i <= N && cin>>temp; i++)
	{
		Friends.push_back(temp);
		int n1;
		cin>>n1;
		for (int j = 1; j <= n1 && cin>>temp; j++)
			Temp.push_back(temp);
	}

	sort(Friends.begin(), Friends.end());
	sort(Temp.begin(), Temp.end());
	Temp.erase(unique(Temp.begin(), Temp.end()), Temp.end());

	for (int i = 0; i < Temp.size(); i++)
		if (!binary_search(Friends.begin(), Friends.end(), Temp[i]))
			FoF.push_back(Temp[i]);

	cout<<FoF.size()<<endl;
	return 0;
}
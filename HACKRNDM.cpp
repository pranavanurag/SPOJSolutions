#include <bits/stdc++.h>

using namespace std;

int n, k;
vector <int> a;

int number_of_occurences(int x)
{
	if (binary_search(a.begin(), a.end(), x))
		return distance(lower_bound(a.begin(), a.end(), x), upper_bound(a.begin(), a.end(), x));
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	int temp;
	while (n-- && cin>>temp)
		a.push_back(temp);
	sort(a.begin(), a.end());

	int ans = 0;
	for (auto x: a)
	{
		if (k == 0)
			ans += number_of_occurences(x + k) - 1;
		else if ((x + k) != (x - k))
			ans += number_of_occurences(x + k) + number_of_occurences(x - k);
		else
			ans += number_of_occurences(x + k);
	}
	cout<<ans/2<<endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define N (int)(3*1e6)

long double a, pre_log[N+ 1];

void pre()
{
	pre_log[0] = -1, pre_log[1] = 0;
	for (int i = 2; i <= N; i++)
		pre_log[i] = pre_log[i - 1] + log(i);
}

int search()
{
	int low = 1, high = N, mid = low + (high - low)/2;
	while (low < high)
	{
		if (pre_log[mid] <= mid*log(a))
			low = mid + 1;
		else
			high = mid;
		mid = low + (high - low)/2;
	}
	return mid;
}

int main()
{
	ios::sync_with_stdio(false);
	
	pre();
	int t;
	cin>>t;
	while (t--)
	{
		cin>>a;
		cout<<search()<<endl;
	}
	return 0;
}
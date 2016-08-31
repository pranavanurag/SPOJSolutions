#include <iostream>
#include <set>

using namespace std;

int Lazy[40000001];

void Refresh()
{
	for (int i = 0; i <= 40000000; i++)
		Lazy[i] = 0;
}

void Update(int i, int STx1, int STx2, int x1, int x2, int V)
{
	if (Lazy[i])
	{
		if (STx1 != STx2)
		{
			Lazy[2*i] = Lazy[2*i + 1] = Lazy[i];
			Lazy[i] = 0;
		}
	}
	if (STx1 > STx2 || x1 > x2 || STx1 > x2 || STx2 < x1)
		return;
	if (STx1 >= x1 && STx2 <= x2)
		Lazy[i] = V;
	else
	{
		int STxm = (STx1 + STx2)/2;
		Update(2*i, STx1, STxm, x1, x2, V);
		Update(2*i + 1, STxm + 1, STx2, x1, x2, V);
	}
}

set <int> S;

void Count(int i, int STx1, int STx2)
{
	if (Lazy[i])
	{
		S.insert(Lazy[i]);
		return;
	}
	if (STx1 >= STx2)
		return;
	else
	{
		int STxm = (STx1 + STx2)/2;
		Count(2*i, STx1, STxm);
		Count(2*i + 1, STxm + 1, STx2);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T, N, L, R;
	cin>>T;
	while (T--)
	{
		cin>>N;
		Refresh();
		for (int i = 1; i <= N; i++)
		{
			cin>>L>>R;
			Update(1, 1, 10000000, L, R, i);
		}
		S.clear();
		Count(1, 1, 10000000);
		cout<<S.size()<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct Node
{
	long long Sum, Lazy;
	Node() {Sum = Lazy = 0;}
};

Node SegTree[4000001];

void Refresh()
{
	for (int i = 0; i <= 4000000; i++)
		SegTree[i] = Node();
}

void UpdateRange(int i, int STx1, int STx2, int x1, int x2, long long V)
{
	if (SegTree[i].Lazy != 0)
	{
		SegTree[i].Sum += (STx2 - STx1 + 1)*SegTree[i].Lazy;

		if (STx1 != STx2)
		{
			SegTree[2*i].Lazy += SegTree[i].Lazy;
			SegTree[2*i + 1].Lazy += SegTree[i].Lazy;
		}
		SegTree[i].Lazy = 0;
	}

	if (x1 > x2 || x2 < STx1 || x1 > STx2 || STx1 > STx2)
		return;

	if (STx1 >= x1 && STx2 <= x2) 
	{ 
		SegTree[i].Sum += (STx2 - STx1 + 1)*V;

		if (STx1 != STx2)
		{
			SegTree[2*i].Lazy += V;
			SegTree[2*i + 1].Lazy += V;
		}
	}
	else
	{
		int STxm = (STx1 + STx2)/2;
		UpdateRange(2*i, STx1, STxm, x1, x2, V);
		UpdateRange(2*i + 1, STxm + 1, STx2, x1, x2, V);
		SegTree[i].Sum = SegTree[2*i].Sum + SegTree[2*i + 1].Sum;;
	}
}

Node Query(int i, int STx1, int STx2, int x1, int x2)
{
	if (SegTree[i].Lazy != 0)
	{
		SegTree[i].Sum += (STx2 - STx1 + 1)*SegTree[i].Lazy;

		if (STx1 != STx2)
		{
			SegTree[2*i].Lazy += SegTree[i].Lazy;
			SegTree[2*i + 1].Lazy += SegTree[i].Lazy;
		}
		SegTree[i].Lazy = 0;
	}

	if (x1 > x2 || x2 < STx1 || x1 > STx2 || STx1 > STx2)
		return Node();

	if (STx1 >= x1 && STx2 <= x2)
		return SegTree[i];

	int STxm = (STx1 + STx2)/2;
	Node Ans, Left = Query(2*i, STx1, STxm, x1, x2), Right = Query(2*i + 1, STxm + 1, STx2, x1, x2);
	Ans.Sum = Left.Sum + Right.Sum;
	return Ans;
}

int main()
{
	int T, N, Q, IsQuery, L, R;
	long long V;
	cin>>T;
	while (T--)
	{
		Refresh();
		cin>>N>>Q;
		while (Q--)
		{
			cin>>IsQuery>>L>>R;
			if (IsQuery)
				cout<<Query(1, 1, N, L, R).Sum<<endl;
			else
			{
				cin>>V;
				UpdateRange(1, 1, N, L, R, V);
			}
		}
	}
	return 0;
}
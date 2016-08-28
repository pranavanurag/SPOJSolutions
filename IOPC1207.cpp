#include <stdio.h>

using namespace std;

#define ull unsigned long long

struct Node
{
	ull Value, Lazy;
	Node() {Value = 0, Lazy = 0;}
};

class SegmentTree
{
private:
	Node SegTree[400001];
	int N;

	void Merge(Node& Ans, Node&Left, Node& Right)
	{
		Ans.Value = Left.Value + Right.Value;
	}

	void UpdateNode(int i, int STx1, int STx2, int P)
	{
		if (P%2 == 1)
			SegTree[i].Value = (STx2 - STx1 + 1) - SegTree[i].Value;
	}

	void PropogateLazy(int i, int STx1, int STx2)
	{
		if (SegTree[i].Lazy)
		{
			UpdateNode(i, STx1, STx2, SegTree[i].Lazy);
			if (STx1 != STx2)
				SegTree[2*i].Lazy += SegTree[i].Lazy, SegTree[2*i + 1].Lazy += SegTree[i].Lazy;
			SegTree[i].Lazy = 0;
		}
	}

	void UpdateRange(int i, int STx1, int STx2, int x1, int x2)
	{
		PropogateLazy(i, STx1, STx2);
		if (STx1 > STx2 || x1 > x2 || x2 < STx1 || x1 > STx2)
			return;
		if (STx1 >= x1 && STx2 <= x2)
		{
			UpdateNode(i, STx1, STx2, 1);
			if (STx1 != STx2)
				SegTree[2*i].Lazy++, SegTree[2*i + 1].Lazy++;
		}
		else
		{
			int STxm = (STx1 + STx2)/2;
			UpdateRange(2*i, STx1, STxm, x1, x2);
			UpdateRange(2*i + 1, STxm + 1, STx2, x1, x2);
			Merge(SegTree[i], SegTree[2*i], SegTree[2*i + 1]);
		}
	}

	Node Query(int i, int STx1, int STx2, int x1, int x2)
	{
		PropogateLazy(i, STx1, STx2);
		if (STx1 > STx2 || x1 > x2 || x2 < STx1 || x1 > STx2)
			return Node();
		if (STx1 >= x1 && STx2 <= x2)
			return SegTree[i];
		int STxm = (STx1 + STx2)/2;
		Node Ans, Left = Query(2*i, STx1, STxm, x1, x2), Right = Query(2*i + 1, STxm + 1, STx2, x1, x2);
		Merge(Ans, Left, Right);
		return Ans;
	}

public:
	void Update(int x1, int x2)
	{
		UpdateRange(1, 1, N, x1, x2);
	}
	ull QueryTree(int x1, int x2)
	{
		return Query(1, 1, N, x1, x2).Value;
	}
	void Refresh()
	{
		for (int i = 0; i <= 400000; i++)
			SegTree[i] = Node();
	}
	void SetN()
	{
		int n;
		scanf("%d", &n);
		N = n;
	}
};

SegmentTree X, Y, Z;

int main()
{
	int T, Q;
	scanf("%d", &T);
	while (T--)
	{
		X.Refresh(), Y.Refresh(), Z.Refresh();
		X.SetN(), Y.SetN(), Z.SetN();
		scanf("%d", &Q);
		while (Q--)
		{
			ull P, X1, X2, Y1, Y2, Z1, Z2;
			scanf("%lld", &P);
			if (P == 0)
			{
				scanf("%lld %lld", &X1, &X2);
				X1++; X2++;
				X.Update(X1, X2);
			}
			else if (P == 1)
			{
				scanf("%lld %lld", &Y1, &Y2);
				Y1++; Y2++;
				Y.Update(Y1, Y2);
			}
			else if (P == 2)
			{
				scanf("%lld %lld", &Z1, &Z2);
				Z1++; Z2++;
				Z.Update(Z1, Z2);
			}
			else
			{
				scanf("%lld %lld %lld %lld %lld %lld", &X1, &Y1, &Z1, &X2, &Y2, &Z2);
				X1++, Y1++, Z1++, X2++, Y2++, Z2++;
				ull Ansx = X.QueryTree(X1, X2), Ansy = Y.QueryTree(Y1, Y2), Ansz = Z.QueryTree(Z1, Z2);
				ull Ansxy = Ansx*(Y2 - Y1 + 1) + Ansy*(X2 - X1 + 1) - 2*Ansx*Ansy;
				ull Ans = ((Y2 - Y1 + 1)*(X2 - X1 + 1) - Ansxy)*Ansz + Ansxy*(Z2 - Z1 + 1 - Ansz);
				printf("%lld\n", Ans);
			}
		}
	}
	return 0;
}
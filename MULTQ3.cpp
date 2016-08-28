#include <stdio.h>

using namespace std;

struct Node
{
	int Rem0, Rem1, Rem2, Lazy;
	Node(int a = 0, int b = 0, int c = 0, int d = 0)
	{Rem0 = a, Rem1 = b, Rem2 = c, Lazy = d;}
};

Node SegTree[400001];
int N, Q;

void UpdateNode(Node& U, int x)
{
	int OldRem0 = U.Rem0, OldRem1 = U.Rem1, OldRem2 = U.Rem2;
	if (x%3 == 1)
		U.Rem1 = OldRem0, U.Rem2 = OldRem1, U.Rem0 = OldRem2;
	else if (x%3 == 2)
		U.Rem1 = OldRem2, U.Rem2 = OldRem0, U.Rem0 = OldRem1;
}

void Merge(Node& Ans, Node& Left, Node& Right)
{
	Ans.Rem0 = Left.Rem0 + Right.Rem0;
	Ans.Rem1 = Left.Rem1 + Right.Rem1;
	Ans.Rem2 = Left.Rem2 + Right.Rem2;
}

void Build(int i, int STx1, int STx2)
{
	if (STx1 > STx2)
		return;
	if (STx1 == STx2)
	{
		SegTree[i] = Node(1, 0, 0, 0);
		return;
	}
	int STxm = (STx1 + STx2)/2;
	Build(2*i, STx1, STxm);
	Build(2*i + 1, STxm + 1, STx2);
	Merge(SegTree[i], SegTree[2*i], SegTree[2*i + 1]);
}

void UpdateRange(int i, int STx1, int STx2, int x1, int x2)
{
	if (SegTree[i].Lazy)
	{
		UpdateNode(SegTree[i], SegTree[i].Lazy);
		if (STx1 != STx2)
		{
			SegTree[2*i].Lazy += SegTree[i].Lazy;
			SegTree[2*i + 1].Lazy += SegTree[i].Lazy;
		}
		SegTree[i].Lazy = 0;
	}
	if (STx1 > STx2 || x1 > x2 || STx1 > x2 || STx2 < x1)
		return;
	if (STx1 >= x1 && STx2 <= x2)
	{
		UpdateNode(SegTree[i], 1);
		if (STx1 != STx2)
		{
			SegTree[2*i].Lazy++;
			SegTree[2*i + 1].Lazy++;
		}
		return;
	}
	int STxm = (STx1 + STx2)/2;
	UpdateRange(2*i, STx1, STxm, x1, x2);
	UpdateRange(2*i + 1, STxm + 1, STx2, x1, x2);
	Merge(SegTree[i], SegTree[2*i], SegTree[2*i + 1]);
}

Node Query(int i, int STx1, int STx2, int x1, int x2)
{
	if (SegTree[i].Lazy)
	{
		UpdateNode(SegTree[i], SegTree[i].Lazy);
		if (STx1 != STx2)
		{
			SegTree[2*i].Lazy += SegTree[i].Lazy;
			SegTree[2*i + 1].Lazy += SegTree[i].Lazy;
		}
		SegTree[i].Lazy = 0;
	}
	if (STx1 > STx2 || x1 > x2 || STx1 > x2 || STx2 < x1)
		return Node();
	if (STx1 >= x1 && STx2 <= x2)
		return SegTree[i];
	int STxm = (STx1 + STx2)/2;
	Node Ans, Left = Query(2*i, STx1, STxm, x1, x2);
	Node Right = Query(2*i + 1, STxm + 1, STx2, x1, x2);
	Merge(Ans, Left, Right);
	return Ans;
}

int main()
{
	scanf("%d %d", &N, &Q);
	Build(1, 1, N);
	while (Q--)
	{
		int A, B, P;
		scanf("%d %d %d", &P, &A, &B);
		A++, B++;
		if (P)
			printf("%d\n", Query(1, 1, N, A, B).Rem0);
		else
			UpdateRange(1, 1, N, A, B);
	}
	return 0;
}
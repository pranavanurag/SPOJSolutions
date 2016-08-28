#include <stdio.h>

using namespace std;

#define scan(x) scanf("%d", &x);

struct Node
{
	int Sum, Lazy;
	Node() {Sum = 0; Lazy = -1;}
};

Node SegTree[40001];
int T, N, Q, L, R, V, A[10001], IsQuery;
bool IsPrime[2000001];

void Refresh()
{
	for (int i = 0; i <= 40000; i++)
		SegTree[i] = Node();
}

void Seive()
{
	IsPrime[0] = IsPrime[1] = 0;
	for (int i = 2; i <= 2000000; i++)
		IsPrime[i] = 1;
	for (int i = 2; i <= 1415; i++)
		if (IsPrime[i])
			for (int j = i*i; j <= 2000000; j += i)
				IsPrime[j] = 0;
}

void PropogateLazy(int i, int STx1, int STx2)
{
	if (SegTree[i].Lazy != -1)
	{
		SegTree[i].Sum = (STx2 - STx1 + 1)*SegTree[i].Lazy;

		if (STx1 != STx2)
			SegTree[2*i].Lazy = SegTree[2*i + 1].Lazy = SegTree[i].Lazy;
		SegTree[i].Lazy = -1;
	}
}

void Build(int i, int STx1, int STx2)
{
	if (STx1 > STx2)
		return;
	if (STx1 == STx2)
		SegTree[i].Sum = A[STx1];
	else
	{
		int STxm = (STx1 + STx2)/2;
		Build(2*i, STx1, STxm);
		Build(2*i + 1, STxm + 1, STx2);
		SegTree[i].Sum = SegTree[2*i].Sum + SegTree[2*i + 1].Sum;
	}
}

void UpdateRange(int i, int STx1, int STx2, int x1, int x2, int V)
{
	PropogateLazy(i, STx1, STx2);

	if (x1 > x2 || STx1 > STx2 || x1 > STx2 || x2 < STx1)
		return;

	if (STx1 >= x1 && STx2 <= x2)
	{
		SegTree[i].Sum = (STx2 - STx1 + 1)*V;
		if (STx1 != STx2)
			SegTree[2*i].Lazy = SegTree[2*i + 1].Lazy = V;
	}
	else
	{
		int STxm = (STx1 + STx2)/2;
		UpdateRange(2*i, STx1, STxm, x1, x2, V);
		UpdateRange(2*i + 1, STxm + 1, STx2, x1, x2, V);
		SegTree[i].Sum = SegTree[2*i].Sum + SegTree[2*i + 1].Sum;
	}
}

Node Query(int i, int STx1, int STx2, int x1, int x2)
{
	PropogateLazy(i, STx1, STx2);
	if (x1 > x2 || STx1 > STx2 || x1 > STx2 || x2 < STx1)
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
	Seive();
	scan(T);
	for (int t = 1; t <= T; t++)
	{
		printf("Case %d:\n", t);
		Refresh();
		scan(N); scan(Q);
		for (int i = 1; i <= N; i++)
		{
			int temp;
			scan(temp);
			A[i] = (IsPrime[temp])?1:0;
		}
		Build(1, 1, N);
		while (Q--)
		{
			scan(IsQuery); scan(L); scan(R);
			if (IsQuery)
				printf("%d\n", Query(1, 1, N, L, R).Sum);
			else
			{
				scan(V);
				UpdateRange(1, 1, N, L, R, IsPrime[V]);
			}
		}
	}
	return 0;
}
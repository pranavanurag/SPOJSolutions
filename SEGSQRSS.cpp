#include <stdio.h>

using namespace std;

#define scan(x) scanf("%d", &x);

struct Node
{
	long long SqSum, Sum, LazyInc, LazySet;
	Node() {SqSum = 0, Sum = 0, LazyInc = 0, LazySet = -1001;}
};

int A[1000001], N, T, Q, P, L, R, V;
Node SegTree[4000001];

void Refresh()
{
	for (int i = 0; i <= 4000000; i++)
		SegTree[i] = Node();
}

void Merge(Node& Ans, Node& Left, Node& Right)
{
	Ans.SqSum = Left.SqSum + Right.SqSum;
	Ans.Sum = Left.Sum + Right.Sum;
}

void PropogateLazy(int i, int STx1, int STx2)
{
	if (SegTree[i].LazyInc != 0)
	{
		SegTree[i].SqSum += (STx2 - STx1 + 1)*SegTree[i].LazyInc*SegTree[i].LazyInc + 2*SegTree[i].LazyInc*SegTree[i].Sum;
		SegTree[i].Sum += (STx2 - STx1 + 1)*SegTree[i].LazyInc;

		if (STx1 != STx2)
		{
			SegTree[2*i].LazyInc += SegTree[i].LazyInc;
			SegTree[2*i + 1].LazyInc += SegTree[i].LazyInc;
		}
		SegTree[i].LazyInc = 0;
	}

	if (SegTree[i].LazySet != -1001)
	{
		SegTree[i].SqSum = (STx2 - STx1 + 1)*SegTree[i].LazySet*SegTree[i].LazySet;
		SegTree[i].Sum = (STx2 - STx1 + 1)*SegTree[i].LazySet;

		if (STx1 != STx2)
			SegTree[2*i].LazySet = SegTree[2*i + 1].LazySet = SegTree[i].LazySet;

		SegTree[i].LazySet = -1001;
	}
}

void Build(int i, int STx1, int STx2)
{
	if (STx1 > STx2)
		return;
	if (STx1 == STx2)
	{
		SegTree[i].SqSum = A[STx1]*A[STx1];
		SegTree[i].Sum = A[STx1];
	}
	else
	{
		int STxm = (STx1 + STx2)/2;
		Build(2*i, STx1, STxm);
		Build(2*i + 1, STxm + 1, STx2);
		Merge(SegTree[i], SegTree[2*i], SegTree[2*i + 1]);
	}
}

Node Query(int i, int STx1, int STx2, int x1, int x2)
{
	PropogateLazy(i, STx1, STx2);

	if (STx1 > STx2 || x1 > x2 || STx1 > x2 || STx2 < x1)
		return Node();

	if (STx1 >= x1 && STx2 <= x2)
		return SegTree[i];

	int STxm = (STx1 + STx2)/2;
	Node Ans, Left = Query(2*i, STx1, STxm, x1, x2), Right = Query(2*i + 1, STxm + 1, STx2, x1, x2);
	Merge(Ans, Left, Right);
	return Ans;
}

void UpdateRange(int i, int STx1, int STx2, int x1, int x2, int V, int P)
{
	PropogateLazy(i, STx1, STx2);

	if (STx1 > STx2 || x1 > x2 || STx1 > x2 || STx2 < x1)
		return;

	if (STx1 >= x1 && STx2 <= x2)
	{
		if (P == 1)
		{
			SegTree[i].SqSum += (STx2 - STx1 + 1)*V*V + 2*V*SegTree[i].Sum;
			SegTree[i].Sum += (STx2 - STx1 + 1)*V;

			if (STx1 != STx2)
			{
				SegTree[2*i].LazyInc += V;
				SegTree[2*i + 1].LazyInc += V;
			}
		}
		if (P == 0)
		{
			SegTree[i].SqSum = (STx2 - STx1 + 1)*V*V;
			SegTree[i].Sum = (STx2 - STx1 + 1)*V;

			if (STx1 != STx2)
				SegTree[2*i].LazySet = SegTree[2*i + 1].LazySet = V;
		}
		return;
	}

	int STxm = (STx1 + STx2)/2;
	UpdateRange(2*i, STx1, STxm, x1, x2, V, P);
	UpdateRange(2*i + 1, STxm + 1, STx2, x1, x2, V, P);
	Merge(SegTree[i], SegTree[2*i], SegTree[2*i + 1]);
}

int main()
{
	scan(T);
	for (int t = 1; t <= T; t++)
	{
		Refresh();
		scan(N);
		scan(Q);
		printf("Case %d:\n", t);
		for (int i = 1; i <= N; i++)
			scan(A[i]);
		Build(1, 1, N);
		while (Q--)
		{
			scan(P); scan(L); scan(R);
			if (P == 1 || P == 0)
			{
				scan(V);
				UpdateRange(1, 1, N, L, R, V, P);
			}
			else
			{
				Node Ans = Query(1, 1, N, L, R);
				printf("%lld\n", Ans.SqSum);
			}
		}
	}
	return 0;
}
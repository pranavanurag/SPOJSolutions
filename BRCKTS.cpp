#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int UnmatchedOpen, UnmatchedClosed;

	Node()
	{
		UnmatchedClosed = UnmatchedOpen = 0;
	}
};

int N, M, A[30001];
char x[30001];
Node SegTree[120001];

void Refresh()
{
	for (int i = 0; i <= 120000; i++)
		SegTree[i].UnmatchedOpen = SegTree[i].UnmatchedClosed = 0;
}

void Merge(Node& X, Node& Left, Node& Right)
{
	int Satisfied = min(Left.UnmatchedOpen, Right.UnmatchedClosed);
	X.UnmatchedClosed = Left.UnmatchedClosed + Right.UnmatchedClosed - Satisfied;
	X.UnmatchedOpen = Left.UnmatchedOpen + Right.UnmatchedOpen - Satisfied;
}

void Build(int i, int x1, int x2)
{
	if (x1 > x2)
		return;

	if (x1 == x2)
	{
		if (A[x1] == -1)
			SegTree[i].UnmatchedOpen++;
		else
			SegTree[i].UnmatchedClosed++;
	}
	else
	{
		int xm = (x1 + x2)/2;
		Build(2*i, x1, xm);
		Build(2*i + 1, xm + 1, x2);
		Merge(SegTree[i], SegTree[2*i], SegTree[2*i + 1]);
	}
}

void Update(int i, int STx1, int STx2, int x, int Value)
{
	if (STx1 > STx2 || x < STx1 || x > STx2)
		return;
	if (STx1 == STx2)
	{
		if (Value == -1)
		{
			SegTree[i].UnmatchedClosed = 0;
			SegTree[i].UnmatchedOpen = 1;
		}
		else
		{
			SegTree[i].UnmatchedOpen = 0;
			SegTree[i].UnmatchedClosed = 1;
		}
	}
	else
	{
		int STxm = (STx1 + STx2)/2;
		Update(2*i, STx1, STxm, x, Value);
		Update(2*i + 1, STxm + 1, STx2, x, Value);
		Merge(SegTree[i], SegTree[2*i], SegTree[2*i + 1]);
	}
}

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		Refresh();
		printf("Test %d:\n", i);
		scanf("%d", &N);
		scanf("%s", x);

		for (int i = 0; i < N; i++)
			A[i+1] = (x[i] == '(')?-1:1;

		Build(1, 1, N);
		int M;
		scanf("%d", &M);
		while (M--)
		{
			int k;
			scanf("%d", &k);
			if (k)
			{
				Update(1, 1, N, k, -A[k]);
				A[k] = -A[k];
			}
			else
			{
				Node Ans = SegTree[1];
				if (Ans.UnmatchedClosed + Ans.UnmatchedOpen == 0)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}
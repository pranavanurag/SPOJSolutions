#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

struct Node
{
	ull Sum;
	Node(ull x = 0)
	{Sum = x;}
};

Node SegTree[400001];
ull A[100001];
int N;

void Merge(Node& Ans, Node &Left, Node& Right)
{
	Ans.Sum = Left.Sum + Right.Sum;
}

void Build(int i, int STx1, int STx2)
{
	if (STx1 > STx2)
		return;
	if (STx1 == STx2)
		SegTree[i] = Node(A[STx2]);
	else
	{
		int STxm = (STx1 + STx2)/2;
		Build(2*i, STx1, STxm);
		Build(2*i + 1, STxm + 1, STx2);
		Merge(SegTree[i], SegTree[2*i], SegTree[2*i + 1]);
	}
}

void UpdateRange(int i, int STx1, int STx2, int x1, int x2)
{
	if (STx1 > STx2 || x1 > x2 || x2 < STx1 || x1 > STx2)
		return;
	if (SegTree[i].Sum == STx2 - STx1 + 1)
		return;
	if (STx1 == STx2)
		SegTree[i].Sum = sqrt(SegTree[i].Sum);
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
	if (STx1 > STx2 || x1 > x2 || x2 < STx1 || x1 > STx2)
		return Node();
	if (STx1 >= x1 && STx2 <= x2)
		return SegTree[i];
	else
	{
		int STxm = (STx1 + STx2)/2;
		Node Left = Query(2*i, STx1, STxm, x1, x2), Right = Query(2*i + 1, STxm + 1, STx2, x1, x2), Ans;
		Merge(Ans, Left, Right);
		return Ans;
	}
}

int main()
{
	int t = 1;
	while (cin>>N)
	{
		printf("Case #%d:\n", t);
		for (int i = 1; i <= N; i++)
			scanf("%lld", &A[i]);
		Build(1, 1, N);
		int Q;
		scanf("%d", &Q);
		while (Q--)
		{
			int IsQuery, A, B;
			scanf("%d %d %d", &IsQuery, &A, &B);
			int X1 = min(A, B);
			int X2 = max(A, B);
			if (IsQuery)
				printf("%lld\n", Query(1, 1, N, X1, X2).Sum);
			else
				UpdateRange(1, 1, N, X1, X2);
		}
		printf("\n");
		t++;
	}	
	return 0;
}
#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
	long MaxPrefixSum, MaxSuffixSum, Max, Total;
}SegTree[200001];

long A[50001];
int n;

void Build(int i, int x1, int x2)
{
	if (x1 > x2)
		return;
	if (x1 == x2)
	{
		SegTree[i].MaxPrefixSum = A[x1];
		SegTree[i].MaxSuffixSum = A[x1];
		SegTree[i].Max = A[x1];	
		SegTree[i].Total = A[x1];
	}
	else
	{
		int xm = (x1 + x2)/2;
		Build(2*i, x1, xm);
		Build(2*i+1, xm+1, x2);

		Node Left = SegTree[2*i];
		Node Right = SegTree[2*i+1];

		SegTree[i].MaxPrefixSum = max(Left.MaxPrefixSum, max(Left.Total, Left.Total + Right.MaxPrefixSum));
		SegTree[i].MaxSuffixSum = max(Right.MaxSuffixSum, max(Right.Total, Right.Total + Left.MaxSuffixSum));
		SegTree[i].Total = Left.Total + Right.Total;
		SegTree[i].Max = max(Left.Max, max(Right.Max, max(SegTree[i].Total, max(SegTree[i].MaxPrefixSum, max(SegTree[i].MaxSuffixSum, Left.MaxSuffixSum + Right.MaxPrefixSum)))));
	}
	//printf("Build(%d, %d, %d): Max = %ld, MPS = %ld, MSS = %ld, Total = %ld\n", i, x1, x2, SegTree[i].Max, SegTree[i].MaxPrefixSum, SegTree[i].MaxSuffixSum, SegTree[i].Total);
}

Node Query(int i, int STx1, int STx2, int x1, int x2)
{
	//printf("Query(%d, %d, %d, %d, %d)\n", i, STx1, STx2, x1, x2);

	if (STx1 > x2 || STx2 < x1 || x1 > x2)
		return Node();

	if (STx1 >= x1 && STx2 <= x2)
		return SegTree[i];

	int STxm = (STx1 + STx2)/2;

	if (x2 <= STxm)
		return Query(2*i, STx1, STxm, x1, x2);

	if (x1 >= STxm+1)
		return Query(2*i+1, STxm+1, STx2, x1, x2);

	Node Left = Query(2*i, STx1, STxm, x1, x2);
	Node Right = Query(2*i+1, STxm+1, STx2, x1, x2);

	Node Ans;
	Ans.MaxPrefixSum = max(Left.MaxPrefixSum, max(Left.Total, Left.Total + Right.MaxPrefixSum));
	Ans.MaxSuffixSum = max(Right.MaxSuffixSum, max(Right.Total, Right.Total + Left.MaxSuffixSum));
	Ans.Total = Left.Total + Right.Total;
	Ans.Max = max(Left.Max, max(Right.Max, max(Ans.Total, max(Ans.MaxPrefixSum, max(Ans.MaxSuffixSum, Left.MaxSuffixSum + Right.MaxPrefixSum)))));

	return Ans;
}

void Update(int i, int STx1, int STx2, int x, int p)
{
	//printf("Update(%d, %d, %d, %d, %d)\n", i, STx1, STx2, x, p);
	if (STx1 == STx2)
	{
		SegTree[i].Max = p;
		SegTree[i].MaxPrefixSum = p;
		SegTree[i].MaxSuffixSum = p;
		SegTree[i].Total = p;
	}
	else
	{
		int STxm = (STx1 + STx2)/2;

		if (x <= STxm)
			Update(2*i, STx1, STxm, x, p);
		else if (x >= STxm + 1)
			Update(2*i+1, STxm+1, STx2, x, p);

		Node Left = SegTree[2*i];
		Node Right = SegTree[2*i+1];

		SegTree[i].MaxPrefixSum = max(Left.MaxPrefixSum, max(Left.Total, Left.Total + Right.MaxPrefixSum));
		SegTree[i].MaxSuffixSum = max(Right.MaxSuffixSum, max(Right.Total, Right.Total + Left.MaxSuffixSum));
		SegTree[i].Total = Left.Total + Right.Total;
		SegTree[i].Max = max(Left.Max, max(Right.Max, max(SegTree[i].Total, max(SegTree[i].MaxPrefixSum, max(SegTree[i].MaxSuffixSum, Left.MaxSuffixSum + Right.MaxPrefixSum)))));
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%ld", &A[i]);

	Build(1, 1, n);

	int M, x, y, isQuery;
	scanf("%d", &M);
	while (M--)
	{
		scanf("%d %d %d", &isQuery, &x, &y);
		if (isQuery)
			printf("%ld\n", Query(1, 1, n, x, y).Max);
		else
			Update(1, 1, n, x, y);
	}
	return 0;
}
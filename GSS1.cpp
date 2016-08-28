#include <iostream>
#include <stdio.h>

using namespace std;

long A[50000];
int n;

struct Node
{
	long MaxPrefixSum, MaxSuffixSum, Max, Total;
}SegTree[200000];

void Merge(Node& Ans, Node& Left, Node& Right)
{
	Ans.MaxPrefixSum = max(Left.MaxPrefixSum, max(Left.Total, Left.Total + Right.MaxPrefixSum));
	Ans.MaxSuffixSum = max(Right.MaxSuffixSum, max(Right.Total, Right.Total + Left.MaxSuffixSum));
	Ans.Total = Left.Total + Right.Total;
	Ans.Max = max(Ans.MaxPrefixSum, max(Ans.MaxSuffixSum, max(Ans.Total, max(Left.MaxSuffixSum + Right.MaxPrefixSum, max(Left.Max, Right.Max)))));
}

void Build(int i, int x, int y)	//i, x, and y follow 1-based indexing
{
	if (x == y)
		SegTree[i-1].MaxPrefixSum = SegTree[i-1].MaxSuffixSum = SegTree[i-1].Max = SegTree[i-1].Total = A[x-1];
	else
	{
		int m = (x + y)/2;
		Build(2*i, x, m);
		Build(2*i+1, m+1, y);
		Merge(SegTree[i-1], SegTree[2*i - 1], SegTree[2*i]);
	} 	
}

Node Query(int i, int STx, int STy, int x, int y) //i, x, and y follow 1-based indexing
{
	if (STx >= x && STy <= y)	//all required data is in current index
		return SegTree[i-1];
	else
	{
		int STm = (STx + STy)/2;
		//left child interval: STx - STm. right child interval: STm+1 - STy.

		if (x <= STm && STx <= y && y >= STm+1 && STy >= x)	//need data from left and right of current node
		{
			Node Ans, AnsL = Query(2*i, STx, STm, x, y), AnsR = Query(2*i+1, STm+1, STy, x, y);
			Merge(Ans, AnsL, AnsR);
			return Ans;
		}

		else if (x <= STm && STx <= y)	//all required data is on the left
			return Query(2*i, STx, STm, x, y);

		else if (y >= STm+1 && STy >= x)	//all required data is on the right
			return Query(2*i+1, STm+1, STy, x, y);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%ld", &A[i]);

	Build(1, 1, n);

	int M, x, y;
	scanf("%d", &M);
	while (M--)
	{
		scanf("%d %d", &x, &y);
		long Q = Query(1, 1, n, x, y).Max;
		printf("%ld", Q);
		printf("\n");
	}
	return 0;
}

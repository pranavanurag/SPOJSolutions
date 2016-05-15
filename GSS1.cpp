#include <iostream>
#include <stdio.h>

using namespace std;

long A[50000];
int n;

struct Node
{
	long MaxPrefixSum, MaxSuffixSum, Max, Total;
}SegTree[200000];

inline long max(long x, long y, long z, long a = -1000000000, long b = -1000000000, long c = -1000000000)
{
	if (x >= y && x >= z && x >= a && x >= b && x >= c)
		return x;
	if (y >= x && y >= z && y >= a && y >= b && y >= c)
		return y;
	if (z >= y && z >= x && z >= a && z >= b && z >= c)
		return z;
	if (a >= y && a >= z && a >= x && a >= b && a >= c)
		return a;
	if (b >= y && b >= z && b >= a && b >= x && b >= c)
		return b;
	return c;
}

void Build(int i, int x, int y)	//i, x, and y follow 1-based indexing
{
	if (x == y)
		SegTree[i-1].MaxPrefixSum = SegTree[i-1].MaxSuffixSum = SegTree[i-1].Max = SegTree[i-1].Total = A[x-1];
	else
	{
		int m = (x + y)/2;

		//recursing
		Build(2*i, x, m);
		Build(2*i+1, m+1, y);
		
		//assigning MaxPrefixSum
		SegTree[i-1].MaxPrefixSum = max(SegTree[2*i-1].MaxPrefixSum, SegTree[2*i-1].Total, SegTree[2*i-1].Total + SegTree[2*i].MaxPrefixSum);

		//assigning MaxSuffixSum
		SegTree[i-1].MaxSuffixSum = max(SegTree[2*i].MaxSuffixSum, SegTree[2*i].Total, SegTree[2*i].Total + SegTree[2*i-1].MaxSuffixSum);

		//assigning Total
		SegTree[i-1].Total = SegTree[2*i-1].Total + SegTree[2*i].Total;

		//calculating Max
		SegTree[i-1].Max = max(SegTree[i-1].MaxPrefixSum, SegTree[i-1].MaxSuffixSum, SegTree[i-1].Total, SegTree[2*i-1].MaxSuffixSum + SegTree[2*i].MaxPrefixSum, SegTree[2*i-1].Max, SegTree[2*i].Max);
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
			Node Ans, AnsL, AnsR;

			AnsL = Query(2*i, STx, STm, x, y);
			AnsR = Query(2*i+1, STm+1, STy, x, y);

			Ans.MaxPrefixSum = max(AnsL.MaxPrefixSum, AnsL.Total, AnsL.Total + AnsR.MaxPrefixSum);
			Ans.MaxSuffixSum = max(AnsR.MaxSuffixSum, AnsR.Total, AnsR.Total + AnsL.MaxSuffixSum);
			Ans.Total = AnsL.Total + AnsR.Total;
			Ans.Max = max(Ans.MaxPrefixSum, Ans.MaxSuffixSum, Ans.Total, AnsL.MaxSuffixSum + AnsR.MaxPrefixSum, AnsL.Max, AnsR.Max);

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

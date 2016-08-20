#include <stdio.h>
#include <algorithm>

using namespace std;

struct Node
{
	int Max, Max2;
	Node() {Max = 0, Max2 = 0;}
};

Node SegTree[400001];
int A[100001], N, Q;

void Merge(Node& Ans, Node &Left, Node &Right)
{
	int Temp[4] = {Left.Max, Left.Max2, Right.Max, Right.Max2};
	sort(Temp, Temp + 4);
	Ans.Max = Temp[3];
	Ans.Max2 = Temp[2];
}

void Build(int i, int STx1, int STx2)
{
	if (STx1 > STx2)
		return;
	if (STx1 == STx2)
		SegTree[i].Max = A[STx1];
	else
	{
		int STxm = (STx1 + STx2)/2;
		Build(2*i, STx1, STxm);
		Build(2*i + 1, STxm + 1, STx2);
		Merge(SegTree[i], SegTree[2*i], SegTree[2*i + 1]);
	}
}

void Update(int i, int STx1, int STx2, int x, int V)
{
	if (STx1 > STx2 || STx1 > x || STx2 < x)
		return;
	if (STx1 == STx2)
		SegTree[i].Max = V;
	else
	{
		int STxm = (STx1 + STx2)/2;
		Update(2*i, STx1, STxm, x, V);
		Update(2*i + 1, STxm + 1, STx2, x, V);
		Merge(SegTree[i], SegTree[2*i], SegTree[2*i + 1]);
	}
}

Node Query(int i, int STx1, int STx2, int x1, int x2)
{
	if (STx1 > STx2 || x1 > x2 || STx1 > x2 || STx2 < x1)
		return Node();
	if (STx1 >= x1 && STx2 <= x2)
		return SegTree[i];

	int STxm = (STx1 + STx2)/2;
	Node Ans, Left = Query(2*i, STx1, STxm, x1, x2), Right = Query(2*i + 1, STxm + 1, STx2, x1, x2);
	Merge(Ans, Left, Right);
	return Ans;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);
	Build(1, 1, N);
	scanf("%d", &Q);
	while (Q--)
	{
		int L, R;
		char P;
		scanf(" %c %d %d", &P, &L, &R);
		if (P == 'U')
			Update(1, 1, N, L, R);
		else
		{
			Node Ans = Query(1, 1, N, L, R);
			printf("%d\n", Ans.Max + Ans.Max2);
		}
	}	
	return 0;
}
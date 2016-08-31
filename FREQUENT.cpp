#include <iostream>

using namespace std;

struct Node
{
	int LeftFreq, LeftNumber, MaxFreq, MaxNumber, RightFreq, RightNumber;
	Node(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0)
	{LeftFreq = a, LeftNumber = b, MaxFreq = c, MaxNumber = d, RightFreq = e, RightNumber = f;}
	void SetMax(int TheNumber, int TheFrequency)
	{MaxNumber = TheNumber, MaxFreq = TheFrequency;}
};

Node SegTree[400001];
int A[100001], N;

void Merge(Node& Ans, Node& Left, Node& Right)
{
	Ans.LeftNumber = Left.LeftNumber;
	Ans.RightNumber = Right.RightNumber;
	if (Left.LeftNumber == Right.LeftNumber)
		Ans.LeftFreq = Left.LeftFreq + Right.LeftFreq;
	else
		Ans.LeftFreq = Left.LeftFreq;

	if (Right.RightNumber == Left.RightNumber)
		Ans.RightFreq = Left.RightFreq + Right.RightFreq;
	else
		Ans.RightFreq = Right.RightFreq;

	Ans.SetMax(Left.MaxNumber, Left.MaxFreq);
	if (Right.MaxFreq > Ans.MaxFreq)
		Ans.SetMax(Right.MaxNumber, Right.MaxFreq);
	if (Left.MaxNumber == Right.MaxNumber && Left.MaxFreq + Right.MaxFreq > Ans.MaxFreq)
		Ans.SetMax(Left.MaxNumber, Left.MaxFreq + Right.MaxFreq);
	if (Left.RightNumber == Right.LeftNumber && Left.RightFreq + Right.LeftFreq > Ans.MaxFreq)
		Ans.SetMax(Left.RightNumber, Left.RightFreq + Right.LeftFreq);
}

void Build(int i, int STx1, int STx2)
{
	if (STx1 > STx2)
		return;
	if (STx1 == STx2)
		SegTree[i] = Node(1, A[STx1], 1, A[STx1], 1, A[STx1]);
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
	if (STx1 > STx2 || x1 > x2 || STx1 > x2 || STx2 < x1)
		return Node();

	Node Ans;
	if (STx1 >= x1 && STx2 <= x2)
		Ans = SegTree[i];
	else
	{
		int STxm = (STx1 + STx2)/2;
		Node Left = Query(2*i, STx1, STxm, x1, x2), Right = Query(2*i + 1, STxm + 1, STx2, x1, x2);
		Merge(Ans, Left, Right);
	}
	return Ans;
}

int main()
{
	ios::sync_with_stdio(0);
	while (cin>>N && N != 0)
	{
		int Q;
		cin>>Q;
		for (int i = 1; i <= N; i++)
			cin>>A[i];
		Build(1, 1, N);
		while (Q--)
		{
			int L, R;
			cin>>L>>R;
			cout<<Query(1, 1, N, L, R).MaxFreq<<endl;
		}
	}
	return 0;
}
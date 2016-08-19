#include <iostream>

using namespace std;

int SegTree[400001], A[100001], Q, L, R, N;

int GCD(int x, int y)
{
	int a = max(x, y), b = min(x, y);
	if (b == 0)
		return a;
	if (a%b == 0)
		return b;
	return GCD(b, a%b);
}

void Build(int i, int STx1, int STx2)
{
	if (STx1 > STx2)
		return;
	if (STx1 == STx2)
		SegTree[i] = A[STx1];
	else
	{
		int STxm = (STx1 + STx2)/2;
		Build(2*i, STx1, STxm);
		Build(2*i + 1, STxm + 1, STx2);
		SegTree[i] = GCD(SegTree[2*i], SegTree[2*i + 1]);
	}
}

int Query(int i, int STx1, int STx2, int x1, int x2)
{
	if (STx1 > STx2 || x1 > x2 || x1 > STx2 || x2 < STx1)
		return 0;
	if (STx1 >= x1 && STx2 <= x2)
		return SegTree[i];

	int STxm = (STx1 + STx2)/2;
	return GCD(Query(2*i, STx1, STxm, x1, x2), Query(2*i + 1, STxm + 1, STx2, x1, x2));
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>N>>Q;
	for (int i = 1; i <= N; i++)
		cin>>A[i];
	Build(1, 1, N);
	while (Q--)
	{
		cin>>L>>R;
		cout<<Query(1, 1, N, L, R)<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long 
#define INF 1000000001

int SegTree[400001], H[100001], N;

ull Max(ull x, ull y)
{
	if (x < y)
		return y;
	return x;
}

void Build(int i, int STx, int STy)
{
	if (STx > STy)
		return;
	if (STx == STy)
		SegTree[i] = STx;
	else
	{
		int STm = (STx + STy)/2;
		Build(2*i, STx, STm);
		Build(2*i+1, STm+1, STy);

		if (H[SegTree[2*i]] < H[SegTree[2*i+1]])
			SegTree[i] = SegTree[2*i];
		else
			SegTree[i] = SegTree[2*i+1];
	}
}

int QueryT(int i, int STx, int STy, int x, int y)
{
	
	if (x > y || STx > STy || x > STy || y < STx)
		return 0;
	if (STx >= x && STy <= y)
		return SegTree[i];

	int STm = (STx + STy)/2;
	int AnsL = QueryT(2*i, STx, STm, x, y),
		AnsR = QueryT(2*i+1, STm+1, STy, x, y);

	if (H[AnsL] < H[AnsR])
		return AnsL;
	return AnsR;
}

int Query(int x, int y)
{
	return QueryT(1, 1, N, x, y);
}

ull LargestArea(int x, int y)
{
	if (x > y)
		return 0;
	if (x == y)
		return H[x];

	int p = Query(x, y);

	ull AnsL = LargestArea(x, p-1);
	ull AnsR = LargestArea(p+1, y);
	ull AnsM = (ull)H[p]*(ull)(y - x + 1);

	return Max(AnsL, Max(AnsR, AnsM));
}

int main()
{
	H[0] = INF;
	while (cin>>N && N != 0)
	{
		for (int i = 1; i <= N; i++)
			cin>>H[i];
		Build(1, 1, N);
		cout<<LargestArea(1, N)<<endl;
	}
	return 0;
}
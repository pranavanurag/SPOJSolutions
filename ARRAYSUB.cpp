#include <iostream>
#include <cmath>

using namespace std;

int N, A[1000001];
int M, SparseTable[1000001][10];

void Build()
{
	M = log2(N) + 1;

	for (int i = 1; i <= N; i++)
		SparseTable[i][0] = A[i];

	for (int j = 1; j < M; j++)
		for (int i = 1; i <= N - pow(2, j) + 1; i++)
			SparseTable[i][j] = max(SparseTable[i][j-1], SparseTable[i + (int)pow(2, j-1)][j-1]);
}


int RMQ(int low, int high)
{
	int l = high - low + 1;
	int k = log2(l);
	return max(SparseTable[low][k], SparseTable[low + l - (int)pow(2, k)][k]);
}

int main()
{
	ios::sync_with_stdio(false);
	int k;
	cin>>N;
	for (int i = 1; i <= N; i++)
		cin>>A[i];
	Build();
	cin>>k;
	for (int k1 = 1; k1 <= N - k + 1; k1++)
		cout<<RMQ(k1, k1+k-1)<<' ';
	cout<<endl;
	return 0;
}
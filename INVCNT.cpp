#include <iostream>

using namespace std;

void Assign(long Destination[], long Source[], long &i, long &j)
{
	Destination[i] = Source[j];
	i++;
	j++;
}

long long Merge(long A[], long p, long m, long q)
{
	long long inv = 0;
	long n1 = m - p + 1; long L[n1];
	long n2 = q - m; long R[n2];
	
	for(long i = 0; i < n1; i++)
		L[i] = A[p + i];
	for(long i = 0; i < n2; i++)
		R[i] = A[m + 1 + i];

	long i = 0, j = 0, k = p;
	while(i < n1 && j < n2)
	{
		if(L[i] < R[j])
			Assign(A, L, k, i);
		else
		{
			inv += (m + 1 + j) - k;
			Assign(A, R, k, j);
		}
	}
	while(i < n1)
		Assign(A, L, k,  i);
	while(j < n2)
		Assign(A, R, k, j);

	return inv;
}

long long CountInversions(long A[], long p, long q)
{
	long long Inversions = 0;
	if(p < q)
	{
		long m = (p + q)/2;
		Inversions += CountInversions(A, p, m);
		Inversions += CountInversions(A, m+1, q);
		Inversions += Merge(A, p, m, q);
	}
	return Inversions;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n;
		cin>>n;
		long A[n];
		for(int i = 0; i < n; i++)
			cin>>A[i];
		cout<<CountInversions(A, 0, n-1)<<endl;
	}
	return 0;
}
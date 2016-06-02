#include <iostream>

using namespace std;

int Remainder(int A, int B[], int N)	//returns remainder A (<= 40000) %B (<= 10^250)
{
	int Q = 0, i = 0;
	while (i < N)
	{
		while (Q < A && i < N)
		{
			Q = 10*Q + B[i];
			i++;
		}
		Q = Q%A;
	}
	return Q;
}

int GCD(int A, int B)
{
	if (A == 0 || B == 0)
		return max(A, B);

	if (A%B == 0)
		return B;

	return GCD(B, A%B);
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--)
	{
		int A, B[251], N;
		string x;
		cin>>A>>x;

		N = x.size();
		for (int i = 0; i < N; i++)
			B[i] = (int)(x[i] - '0');
		if (A == 0)
			cout<<x<<endl;
		else
			cout<<GCD(A, Remainder(A, B, N))<<endl;
	}
	return 0;
}
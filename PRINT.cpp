#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

bool isPrime[46342];
long L, U;
bool A[1000001];

void Print()
{
	if (L == 1)
		L++;

	int N = U - L + 1;
	for (int i = 1; i <= N; i++)
		A[i] = 1;

	for (int i = 2; i <= sqrt(U); i++)
		if (isPrime[i])
		{
			int Prime = i;
			for (int j = (Prime - L%Prime)%Prime + 1; j <= N; j += Prime)
				if (j+L-1 != Prime)
					A[j] = 0;
		}

	for (int i = 1; i <= N; i++)
		if (A[i])
			printf("%ld\n", i+L-1);
}

void Seive()
{
	for (int i = 2; i <= 46341; i++)
		isPrime[i] = 1;

	for (int i = 2; i <= 216; i++)
		if (isPrime[i])
			for (int j = i*i; j <= 46341; j += i)
				isPrime[j] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	Seive();
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%ld %ld", &L, &U);
		Print();
	}
	return 0;
}
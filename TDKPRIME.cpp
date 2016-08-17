#include <bits/stdc++.h>

using namespace std;

bool IsPrime[90000001];
vector <int> Primes;
int N, Q;

void Seive()
{
	for (int i = 2; i <= 90000000; i++)
		IsPrime[i] = 1;
	for (int i = 2; i <= 90000000; i++)
		if (IsPrime[i])
		{
			Primes.push_back(i);
			if (i <= 10000)
			for (int j = i*i; j <= 90000000; j += i)
				IsPrime[j] = 0;
		}
}

int main()
{
	Seive();
	scanf("%d", &Q);
	while (Q--)
	{
		scanf("%d", &N);
		printf("%d\n", Primes[N-1]);
	}
	return 0;
}
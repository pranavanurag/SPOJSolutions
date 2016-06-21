#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cmath>

using namespace std;

#define scan(x) scanf("%d", &x)
#define print(x) printf("%d\n", x);

int NumberofDiv(int x)
{
	if (x == 1)
		return 1;

	int ans = 0;
	for (int i = 1; i < sqrt(x); i++)
		if (x%i == 0)
			ans = ans + 2;

	int sq = sqrt(x);
	if (sq*sq == x)
		ans++;

	return ans;
}

int GCD(int a, int b)
{
	int x1 = max(a, b),
		x2 = min(a, b);
	if (x2 == 0)
		return x1;
	if (x1%x2 == 0)
		return x2;
	return GCD(x2, x1%x2);
}

int main()
{
	int t;
	scan(t);
	while (t--)
	{
		int a, b;
		scan(a);
		scan(b);
		print(NumberofDiv(GCD(a, b)));
	}
	return 0;
}
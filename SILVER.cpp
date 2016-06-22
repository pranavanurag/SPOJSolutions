#include <iostream>
#include <cmath>

using namespace std;

#define scan(x) scanf("%d", &x)
#define print(x) printf("%d\n", x)

int main()
{
	int n;
	while (scan(n) && n != 0)
		print((int)log2(n));
	return 0;
}
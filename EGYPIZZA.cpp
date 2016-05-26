#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int q = 0, h = 0, tq = 0;
	string x;
	for (int i = 0; i < n && cin>>x; i++)
		if (x == "1/4")
			q++;
		else if (x == "1/2")
			h++;
		else if (x == "3/4")
			tq++;

	int ans = 1;	//pizza for host

	ans += h/2;	//combining halves with themselves
	h = h%2;	// h = 1 or h = 0

	ans += tq;	//all three-quarters

	if (q >= tq)	//combining three-quarters with quarters
		q -= tq;
	else
		q = 0;

	tq = 0;	//three-quarters taken care of

	ans += q/4;	//combining quarters with themselves
	q = q%4;	//q = 0, q = 1, q = 2 or q = 3

	if (h != 0)	//h = 1
		if (q <= 2)	//q = 0, 1, 2
			ans += 1;

		else	//q = 3
			ans += 2;

	else	//h = 0
		if (q > 0)	//q = 1, 2, 3; combine within themselves
			ans += 1;

	cout<<ans<<endl;
	return 0;
}
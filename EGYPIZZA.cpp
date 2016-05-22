/*input
37 
1/2 
1/2 
1/4 
1/2 
3/4 
1/4 
1/2 
3/4 
3/4 
1/4 
1/4 
1/2 
3/4 
3/4 
1/2 
1/4 
3/4 
1/4 
1/2 
3/4 
1/2 
1/2 
1/2 
3/4 
1/4 
1/4 
1/4 
1/4 
1/4 
3/4 
1/4 
1/4 
1/4 
3/4 
1/4 
1/4 
1/4 
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n, Fourths = 0, Halves = 0, ThreeQuarters = 0;
	cin>>n;

	for (int i = 0; i < n; i++)
	{
		string x;
		cin>>x;
		if (x == "1/4")
			Fourths++;
		else if (x == "1/2")
			Halves++;
		else if (x == "3/4")
			ThreeQuarters++;
	}

	int ans = 1;	//1 pizza for host

	cout<<Fourths<<' '<<Halves<<' '<<ThreeQuarters<<endl;

	//four fourths make a whole
	ans += Fourths/4;
	Fourths = Fourths%4;

	//two fourths and a half make a whole
	if (Fourths > 1 && Fourths/2 >= Halves)
	{
		ans += Halves;
		Fourths -= 2*Halves;
		Halves = 0;
	}
	else
	{
		ans += Fourths/2;
		Halves -= Fourths/2;
		Fourths = Fourths%2;
	}

	//two halves make a whole
	ans += Halves/2;
	Halves = Halves%2;

	//a threequarters and a fourth make a whole
	if (Fourths >= ThreeQuarters)
	{
		ans += ThreeQuarters;
		Fourths -= ThreeQuarters;
		ThreeQuarters = 0;
	}
	else
	{
		ans += Fourths;
		ThreeQuarters -= Fourths;
		Fourths = 0;
	}
	cout<<Fourths<<' '<<Halves<<' '<<ThreeQuarters<<endl;


	ans += Fourths + Halves + ThreeQuarters;
	cout<<ans<<endl;
	return 0;
}
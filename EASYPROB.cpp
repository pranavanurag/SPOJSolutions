#include <iostream>
#include <cmath>

using namespace std;

void rec(int x, bool arg = false)
{
	if(x == 2)
		cout<<"2";
	else if(x == 1)
	{
		if(arg)
			cout<<"2(0)";
		else
			cout<<"";
	}
	else if(x == 3)
		cout<<"2+2(0)";
	else
	{
		int p = log2(x);
		int r = x - pow(2, p);
		cout<<"2(";
		rec(p);
		if(r)
		{	
			cout<<")+";
			rec(r, 1);
		}
		else
			cout<<")";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int a = 137, b = 1315, c = 73, d = 136, e = 255, f = 1384, g = 16385;
	cout<<a<<"="; rec(a); cout<<endl;
	cout<<b<<"="; rec(b); cout<<endl; 
	cout<<c<<"="; rec(c); cout<<endl;
	cout<<d<<"="; rec(d); cout<<endl; 
	cout<<e<<"="; rec(e); cout<<endl;
	cout<<f<<"="; rec(f); cout<<endl;
	cout<<g<<"="; rec(g); cout<<endl;
	return 0;
}

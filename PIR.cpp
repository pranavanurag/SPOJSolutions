#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double TetVolume(double U, double V, double W, double u, double v, double w)
{
	double X, x, Y, y, Z, z;
	X = (w - U + v)*(U + v + w);
	x = (U - v + w)*(v - w + U);
	Y = (u - V + w)*(V + w + u);
	y = (V - w + u)*(w - u + V);
	Z = (v - W + u)*(W + u + v);
	z = (W - u + v)*(u - v + W);
	double a = sqrt(x*Y*Z),
		   b = sqrt(y*Z*X),
		   c = sqrt(z*X*Y),
		   d = sqrt(x*y*z);
	return sqrt((-a + b + c + d)*(a - b + c + d)*(a + b - c + d)*(a + b + c - d))/(192*u*v*w);
}

int main()
{
	double U, V, W, u, v, w;
	int t;
	cin>>t;
	while (t--)
	{
		cin>>v>>w>>u>>U>>V>>W;
		double ans = TetVolume(U, V, W, u, v, w);
		if (U == 0 || V == 0 || W == 0|| u == 0 || v == 0 || w == 0)
			cout<<"0.0000"<<endl;
		else
			cout<<setprecision(4)<<fixed<<ans<<endl;
	}
	return 0;
}
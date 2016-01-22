#include <iostream>
#include <math.h>

using namespace std;

void TERM(float x)
{
	int i = int((sqrt(8*x+1)-1)/2);
	int n = int(x-(i*(i+1)/2));

	if(n == 0)
		if(i%2 == 0)
			cout<<"TERM "<<int(x)<<" IS "<<i<<"/"<<1;
		else
			cout<<"TERM "<<int(x)<<" IS "<<1<<"/"<<i;
	else
	{
		n = (n > 0)?n:-n;
		
		if(n == 1)
			if(i%2 == 0)
				cout<<"TERM "<<int(x)<<" IS "<<i+1<<"/"<<1;
			else
				cout<<"TERM "<<int(x)<<" IS "<<1<<"/"<<i+1;
		
		else	
			if(i%2==0)
				cout<<"TERM "<<int(x)<<" IS "<<i-n+2<<"/"<<n;
			else
				cout<<"TERM "<<int(x)<<" IS "<<n<<"/"<<i-n+2;

	}
	cout<<endl;
}

int main()
{
	int t;
	cin>>t;

	while(t-- && t >= 0)
	{
		float x;
		cin>>x;
		TERM(x);
	}
	return 0;
}
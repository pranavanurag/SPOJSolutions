#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--)
	{
		unsigned long long int N;
		bool Airborne;	//0 -> Airborne wins, 1 -> Pagfloyd
		cin>>N>>Airborne;
		if(Airborne)
			cout<<"Pagfloyd wins."<<endl;
		else
			cout<<"Airborne wins."<<endl;
	}
	return 0;
}
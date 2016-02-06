#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int setnum;
		cin>>setnum;
		string x;
		cin>>x;
		int c1, c2, c3, c4, c5, c6, c7, c8;
		c1 = c2 = c3 = c4 = c5 = c6 = c7= c8 = 0;
		for(int i = 0; i < x.length()-2; i++)
		{
			if ((x.substr(i, 3)).compare("TTT") == 0) c1++;
			else if ((x.substr(i, 3)).compare("TTH") == 0) c2++;
			else if ((x.substr(i, 3)).compare("THT") == 0) c3++;
			else if ((x.substr(i, 3)).compare("THH") == 0) c4++;
			else if ((x.substr(i, 3)).compare("HTT") == 0) c5++;
			else if ((x.substr(i, 3)).compare("HTH") == 0) c6++;
			else if ((x.substr(i, 3)).compare("HHT") == 0) c7++;
			else if ((x.substr(i, 3)).compare("HHH") == 0) c8++;
		}
		cout<<setnum<<' '<<c1<<' '<<c2<<' '<<c3<<' '<<c4<<' '<<c5<<' '<<c6<<' '<<c7<<' '<<c8<<endl;
	}
	return 0;
}

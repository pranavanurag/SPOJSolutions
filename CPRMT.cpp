#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string x, y;
	while (cin>>x && cin>>y)
	{
		int FreqX[26] = {0}, FreqY[26] = {0};
		
		for (int i = 0; i < x.size(); i++)
			FreqX[(int)(x[i]-'a')]++;
		for (int i = 0; i < y.size(); i++)
			FreqY[(int)(y[i]-'a')]++;

		for (int i = 0; i < 26; i++)
		{
			int p = min(FreqX[i], FreqY[i]);
			for (int j = 0; j < p; j++)
				cout<<(char)(i+97);
		}
		cout<<endl;
	}
	return 0;
}

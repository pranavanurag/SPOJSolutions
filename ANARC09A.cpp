#include <iostream>
#include <stack>

using namespace std;

stack<char> S;

int main()
{
	ios::sync_with_stdio(false);
	string x;
	int c = 1;
	while (cin>>x && x[0] != '-')
	{
		S.push(x[0]);
		for (int i = 1; i < x.size(); i++)
			if (!S.empty() && S.top() == '{' && x[i] == '}') 
				S.pop();
			else
				S.push(x[i]);

		int ans = 0;

		while (!S.empty())
		{
			char x = S.top();
			S.pop();

			if (S.empty())
			{
				ans++;
				break;
			}

			char y = S.top();
			S.pop();

			if (x == '{' && y == '}')
				ans += 2;
			else if ((x == '{' && y == '{' ) || (x == '}' && y == '}'))
				ans += 1;
		}
		cout<<c<<". "<<ans<<endl;
		c++;
	}
	return 0;
}
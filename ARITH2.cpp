#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

long long Value(char word[])
{
	long long sum = 0;
	for (int i = 0; i < strlen(word); ++i)
	{
		if(!isdigit(word[i]))
			return -1;
		else
			sum = sum*10 + int(word[i] - '0');
	}
	return sum;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char c[100];
		cin>>c;
		long long x = Value(c);
		while(1)
		{
			char op;
			cin>>c;
			op = c[0];
			if(op == '=')
				break;
			else
			{
				cin>>c;
				long long y = Value(c);

				if(op == '+')
					x = x + y;
				else if(op == '-')
					x = x - y;
				else if(op == '*')
					x = x * y;
				else if(op == '/')
					x = x / y;
			}
		} 
		cout<<x<<endl;
	}
}

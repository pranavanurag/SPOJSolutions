#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

int Value(char word[])
{
	int sum = 0;
	for (int i = 0; i < strlen(word); ++i)
	{
		if(isalpha(word[i]))
			return -1;
		else
			sum = sum*10 + int(word[i] - '0');
	}
	return sum;
}

int main()
{
	string Input;
	int t;

	cin>>t;
	cin.ignore();
	while(t-- && t >= 0)
	{
		cin.ignore();
		char a[20], b[20], c[20], op;
		cin>>a>>op>>b>>op>>c;

		if(Value(a) < 0)
			cout<<Value(c) - Value(b)<<" + "<<Value(b)<<" = "<<Value(c)<<endl;
		else if(Value(b) < 0)
			cout<<Value(a)<<" + "<<Value(c) - Value(a)<<" = "<<Value(c)<<endl;
		else
			cout<<Value(a)<<" + "<<Value(b)<<" = "<<Value(a) + Value(b)<<endl;
	}
	return 0;
}
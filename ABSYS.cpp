#include <iostream>
#include <string.h>

using namespace std;

string Corrected(string x)
{
	char word[20];
	
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
		getline(std::cin, Input);
		cout<<Corrected(Input);
	}
}
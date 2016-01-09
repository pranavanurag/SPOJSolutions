#include <iostream>
#include <string.h>

using namespace std;

long long Memo[5000];

void RefreshMemo()
{
	for (int i = 0; i < 5000; i++)
		Memo[i] = 0;

	Memo[0] = 1;
}

long long PossibleDecrpytions(char x[], int n)
{

	if(x[n-2] == '1' || (x[n-2] == '2' && int(x[n-1])-48 < 7) )
	{
		Memo[n-1] = PossibleDecrpytions(x, n-2) + PossibleDecrpytions(x, n-1);
		return Memo[n-1];
	}
	else
	{
		Memo[n-1] = PossibleDecrpytions(x, n-1);
		return Memo[n-1];
	}
}

int main()
{
	char String[5000];

	while(1)
	{
		cin>>String;
		if(String[0] == '0')
			break;
		else
		{	
			RefreshMemo();
			cout<<PossibleDecrpytions(String, strlen(String));
		}
	}
	
	return 0;
} 
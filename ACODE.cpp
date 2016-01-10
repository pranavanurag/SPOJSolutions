#include <iostream>
#include <string.h>

using namespace std;

long long Memo[5010]; 

void RefreshMemo()
{
	for (int i =0 ;i < 5010; i++)
		Memo[i] = 0;
	Memo[0] = 1;
}

bool IsValidExpression(char x[])
{
	if ( x[0] == '0')
		return 0;

	for (int i = 1;i < strlen(x); i++)
		if(x[i] == '0')
			if (! (x[i-1] == '1' || x[i-1] == '2') )
				return 0;
			else if( x[i-1] == '0' )
				return 0;

	return 1;
}


void FixExpression(char x[])
{
	for(int i = 1;i < strlen(x); i++)
		if(x[i] == '0')
		{	
			x[i-1] = 'A';
			for(int j = i; j < strlen(x)-1; j++)
				x[j] = x[j+1];
			x[strlen(x)-1] = '\0';
		}
}


long long Decrypt(char x[], int n)
{
	if (Memo[n])
		return Memo[n];

	else
	{
		if (x[n] == 'A')
			Memo[n] = Decrypt(x, n-1);

		else if ( x[n-1] == '1' || ( x[n-1] == '2' && int(x[n])-48 < 7 && int(x[n])-48 >= 0 ))
		{	
			if( n > 1)
				Memo[n] = Decrypt(x, n-1) + Decrypt(x, n-2);
			else
				Memo[n] = Decrypt(x, n-1) + 1;
		}	

		else
			Memo[n] = Decrypt(x, n-1);

		return Memo[n];
	}
}

int main()
{
	char Expression[5010];

	cin>>Expression;
	while(!(strlen(Expression) == 1 && Expression[0] == '0'))
	{
		if(IsValidExpression(Expression))
		{
			RefreshMemo();
			FixExpression(Expression);
			cout<<Decrypt(Expression, strlen(Expression)-1)<<endl;
		}
		else
			cout<<0<<endl;

		cin>>Expression;
	}

	return 0;
}
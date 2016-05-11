/*input
6
1234
9876567876
9999923424
1234254
4265
99
*/
#include <iostream>
#include <string.h>

using namespace std;

void ShowArray(char x[], int n)
{
	for (int i = 0; i < n; ++i)
		cout<<x[i];
	cout<<endl;
}

bool IsAllNines(char x[], int n)
{
	for (int i = 0; i < n; ++i)
		if(x[i] != '9')
			return false;
	return true;
}

bool IsPalindrome(char x[], int n)
{
	for (int i = 0; i < n; ++i)
		if(x[i] != x[n-i-1])
			return false;
	return true;
}

bool Add(char x[], int index, int n)
{
	x[index]++;
	if(n-index-1 != index)
		x[n-index-1]++;

	if(x[index] == ':')
	{
		x[index] = '0';
		x[n-index-1] = '0';
		return true;
	}
	return false;
}

void Next(char x[], int n)
{
	int i = (n-1)/2;
	while(Add(x, i, n))
		i--;
}

bool MGreater(char m[], char x[], int n)
{
	for(int i = 0; i < n; i++)
		if(m[i] > x[i])
			return true;
		else if(m[i] < x[i])
			return false;
}

void ShowNextPalindrome(char x[], int n)
{
	if(IsAllNines(x, n))
	{
		cout<<1;
		for(int i = 0; i < n-1; i++)
			cout<<0;
		cout<<1<<endl;
	}

	else if(IsPalindrome(x, n))
	{
		Next(x, n);
		ShowArray(x, n);
	}

	else
	{
		char m[1000001];

		for(int i = 0; i < n/2 ; i++)
			m[i] = x[i];
		for(int i = n/2; i < n; i++)
			m[i] = x[n-i-1];
		
		if(MGreater(m, x, n))
			ShowArray(m, n);
		else
			ShowNextPalindrome(m, n);
	}
}

int main()
{
	int t;
	cin>>t;
	while(t-- && t >= 0)
	{
		char x[1000001];
		cin>>x;
		ShowNextPalindrome(x, strlen(x));
	}
	return 0;
}
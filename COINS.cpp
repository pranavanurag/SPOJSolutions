#include <iostream>
#include <cstdio>
using namespace std;

struct Map
{
	unsigned long long key;
	unsigned long long value;
};

Map Memo[1000];
int c;

void RefreshMemo()
{
	for(int i=0;i<1000;i++)
	{
		Memo[i].key=0;
		Memo[i].value=0;
	}
	c=-1;
}

int FindKey(unsigned long long x)
{
	for(int i=0;i<1000;i++)
		if(Memo[i].key==x) return i;
	return -1;
}

unsigned long long MaximumDollars(unsigned long long n)
{
	if(n<12)
		return n;
	else
	{
		if(FindKey(n)>0)
			return Memo[FindKey(n)].value;

		else
		{
			unsigned long long x = MaximumDollars(n/2) + MaximumDollars(n/3) + MaximumDollars(n/4);

			if(x>n)
			{
				c++;
				Memo[c].key=n;
				Memo[c].value=x;
			}
			else
			{
				c++;
				Memo[c].key=n;
				Memo[c].value=n;
			}
			return Memo[c].value;
		}
	}
}

int main()
{
	unsigned long long n;

	while(cin>>n)
	{
		RefreshMemo();
		cout<<MaximumDollars(n)<<endl;
	}
	getchar();
	return 0;
}

#include <iostream>
#include <cmath>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;

#define scan(x) scanf("%d", &x)
#define print(x) printf("%d\n", x)
#define INF 100000000

bool Prime[10001];
bool Visited[10001];
int Level[10001];
void Initialize()
{
	for (int i = 1; i <= 10000; i++)
	{	
		Visited[i] = 0;
		Level[i] = -1;
	}
}

void Seive()
{
	for (int i = 2; i <= 10000; i++)
		Prime[i] = 1;

	for (int i = 2; i <= 100; i++)
		if (Prime[i])
			for (int j = i*i; j <= 10000; j += i)
				Prime[j] = 0;
}

int Construct(int Digits[])
{
	int ans = 0;
	for (int i = 1; i <= 4; i++)
		ans = ans*10 + Digits[i];
	return ans;
}

int PPATH(int p1, int p2)
{
	int NewNumber, CurrentPrime;
	queue <int> toExplore;
	toExplore.push(p1);

	Level[p1] = 0;
	while(!toExplore.empty())
	{
		CurrentPrime = toExplore.front();
		toExplore.pop();
		Visited[CurrentPrime] = 1;

		cout<<"From "<<CurrentPrime<<". Can jump to -> ";
		int CurrentPrime_Copy = CurrentPrime;
		if (CurrentPrime == p2)
			break;


		int Digits[5];
		for (int i = 4; i >= 1; i--)
		{
			Digits[i] = CurrentPrime_Copy%10;
			CurrentPrime_Copy /= 10;
		}

		for (int i = 1; i <= 4; i++)
		{
			int Digits_Copy[5];
			for (int j = 1; j <= 4; j++)
				Digits_Copy[j] = Digits[j];

			for (int d = 0; d <= 9; d++)
				if (!(i == 1 && d == 0))
				{
					Digits_Copy[i] = d;
					NewNumber = Construct(Digits_Copy);
					if (Prime[NewNumber] && NewNumber != CurrentPrime && !Visited[NewNumber])
					{
						toExplore.push(NewNumber);
						cout<<NewNumber<<" ";
						if (Level[NewNumber] == -1)
							Level[NewNumber] = Level[CurrentPrime] + 1;
						else
							Level[NewNumber] = min(Level[NewNumber], Level[CurrentPrime] + 1);
					}
				}			
		}
		cout<<endl;	
	}
	return Level[p2];
}

int main()
{
	Seive();
	int n, p1, p2;
	scan(n);

	while (n--)
	{
		Initialize();
		scan(p1); scan(p2);
		print(PPATH(p1, p2));
	}

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

bool CanFit(long N, long C, long StallPositions[], long MinDistance)
{
	long Placed = 1;
	long Pos = StallPositions[0];

	for(int i = 1; i < N; i++)
	{
		if(StallPositions[i] - Pos >= MinDistance)
		{	
			Placed++;
			Pos = StallPositions[i];
			
			if(Placed == C)
				return 1;
		}
	}
	return 0;
}

long BinSearch(long N, long C, long StallPositions[], long Low, long High)
{
	long Mid = Low + (High - Low + 1)/2;
	while(High > Low)
	{

		if (CanFit(N, C, StallPositions, Mid))
			Low = Mid + 1;
		else
			High = Mid - 1;

		Mid = Low + (High - Low + 1)/2;	
	}
	return High;
}

int main()
{
	long StallPositions[1000000];
	long N, C, MaxPos = 0;
	int t;

	cin>>t;
	while(t-- && t >= 0)
	{
		cin>>N>>C;
		for (int i = 0; i < N; i++)
		{
			cin>>StallPositions[i];
			if(MaxPos < StallPositions[i])
				MaxPos = StallPositions[i];
		}
		sort(StallPositions, StallPositions+N);
		cout<<BinSearch(N, C, StallPositions, 1, MaxPos)<<endl;
	}

	return 0;
}
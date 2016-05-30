#include <iostream>
#include <stdio.h>

using namespace std;

#define INF 10000000

int main()
{
	ios::sync_with_stdio(false);

	int t;
	scanf("%d", &t);

	while (t--)
	{
		long N, B;

		scanf("%ld %ld", &N, &B);
		long A[N+1];
		for (long i = 1; i <= N; i++)
			scanf("%ld", &A[i]);

		long Cover = 1, PeopleCrossed = 0, LeastPeopleCrossed = INF, BestCover = 1, Begin = 1;
		for (long End = 1; End <= N; End++)
		{
			PeopleCrossed += A[End];

			while (PeopleCrossed > B)
			{
				PeopleCrossed -= A[Begin];
				Begin++;
			}

			Cover = End - Begin + 1;

			if (Cover > BestCover)
			{
				BestCover = Cover;
				LeastPeopleCrossed = PeopleCrossed;
			}
			else if (Cover == BestCover && PeopleCrossed < LeastPeopleCrossed)
				LeastPeopleCrossed = PeopleCrossed;
		}

		cout<<LeastPeopleCrossed<<" "<<BestCover;
	}
	return 0;
}
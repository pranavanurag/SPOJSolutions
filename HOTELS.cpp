#include <iostream>

using namespace std;

int N, M, Results[3000001], P[3000001];

int main()
{
	ios::sync_with_stdio(false);

	cin>>N>>M;
	for (int i = 1; i <= N; i++)
		cin>>P[i];

	int Best = 0, Begin = 1, WindowSum = 0;

	for (int End = 1; End <= N; End++)
	{
		WindowSum += P[End];

		if (Best < WindowSum && WindowSum <= M)
			Best = WindowSum;

		while (WindowSum > M)
		{
			WindowSum -= P[Begin];
			Begin++;
		}

		if (Best < WindowSum)
			Best = WindowSum;
	}

	cout<<Best<<endl;
	return 0;
}
#include <iostream>

using namespace std;

int Memo[100][100];

void RefreshMemo()
{
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			Memo[i][j] = 101;
}

int PayMin(int Fare[100][100], int i, int j, int MaxRow, int MaxColumn)
{
    if (Memo[i][j] < 101)
        return Memo[i][j];

    else
    {
        if (i == MaxRow)
            Memo[i][j] = Fare[i][j];
        else if (j == 0)
            Memo[i][j] = Fare[i][j] + min(PayMin(Fare, i+1, j+1, MaxRow, MaxColumn), PayMin(Fare, i+1, j, MaxRow, MaxColumn));
        else if (j == MaxColumn)
            Memo[i][j] = Fare[i][j] + min(PayMin(Fare, i+1, j-1, MaxRow, MaxColumn), PayMin(Fare, i+1, j, MaxRow, MaxColumn));
        else
            Memo[i][j] = Fare[i][j] + min(min(PayMin(Fare, i+1, j+1, MaxRow, MaxColumn), PayMin(Fare, i+1, j, MaxRow, MaxColumn) ), min(PayMin(Fare, i+1, j+1, MaxRow, MaxColumn), PayMin(Fare, i+1, j-1, MaxRow, MaxColumn) ));

        return Memo[i][j];
    }
}

int main()
{
	int N, M;
	int Fare[100][100];
	cin>>N>>M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin>>Fare[i][j];

	RefreshMemo();

	if(N != 0 && M != 0)
	{	
		int Ans = PayMin(Fare, 0, 0, N-1, M-1);
		for(int i = 1; i < M; i++)
		{
			int TryI = PayMin(Fare, 0, i, N-1, M-1);
			Ans = min(Ans, TryI);
		}
		cout<<Ans;
	}

	else
		cout<<0;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int Parent, Data, Color;
}Graph[20001];

void ClearGraph()
{
	for (int i = 0; i < 20000; i++)
		Graph[i].Color = -1;
}

void Solve(int N)
{
	ClearGraph();
	if (N == 1)
	{
		cout<<1<<endl;
		return;
	}

	queue <int> ToExplore;
	ToExplore.push(1);

	while (!ToExplore.empty())
	{
		int u = ToExplore.front();
		ToExplore.pop();

		int v1 = (u*10)%N, v2 = (v1 + 1)%N;

		if (Graph[v1].Color == -1)
		{
			ToExplore.push(v1);
			Graph[v1].Parent = u;
			Graph[v1].Data = 0;
			Graph[v1].Color = 0;
		}
		if (Graph[v2].Color == -1)
		{
			ToExplore.push(v2);
			Graph[v2].Parent = u;
			Graph[v2].Data = 1;
			Graph[v2].Color = 0;
		}

		Graph[u].Color = 1;
	}

	vector <int> Ans;
	int u = 0;
	while (u != 1)
	{
		Ans.push_back(Graph[u].Data);
		u = Graph[u].Parent;
	}
	Ans.push_back(1);
	for (int i = Ans.size()-1; i >= 0; i--)
		cout<<Ans[i];
	cout<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T, N;
	cin>>T;
	while (T--)
	{
		cin>>N;
		Solve(N);
	}
	return 0;
}
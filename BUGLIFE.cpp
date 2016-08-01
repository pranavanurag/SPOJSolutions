#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long 
#define scan(x) scanf("%d", &x)

int N, M;
bool Susp;

struct Node
{
	vector <int> Neighbours;
	int Gender, Color;
}Graph[2001];

void ClearGraph()
{
	for (int i = 0; i <= 2000; i++)
	{
		Graph[i].Neighbours.clear();
		Graph[i].Gender = Graph[i].Color = -1;
	}
	Susp = false;
}

void DFSVisit(int u)
{
	Graph[u].Color = 0;
	for (int i = 0; i < Graph[u].Neighbours.size(); i++)
	{
		int v = Graph[u].Neighbours[i];

		if (Graph[v].Color == -1)
		{
			Graph[v].Gender = !Graph[u].Gender;
			DFSVisit(v);
		}
		else if (Graph[v].Gender == Graph[u].Gender)
			Susp = true;
	}
	Graph[u].Color = 1;
}

void DFS()
{
	for (int i = 1; i <= N; i++)
		if (Graph[i].Color == -1)
		{
			Graph[i].Gender = 0;
			DFSVisit(i);
		}
}

int main()
{
	
	int T;
	scan(T);
	for (int t = 1; t <= T; t++)
	{
		ClearGraph();
		scan(N);
		scan(M);
		for (int i = 1; i <= M; i++)
		{
			int v1, v2;
			scan(v1); scan(v2);
			Graph[v1].Neighbours.push_back(v2);
			Graph[v2].Neighbours.push_back(v1);
		}
		DFS();
		printf("Scenario #%d:\n", t);
		if (Susp)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");
	}
	return 0;
}
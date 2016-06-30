#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <time.h>

using namespace std;

#define INF 1000000000
#define DEBUG cout<<"Debug"<<endl
#define ull unsigned long long

int N, M, t, ans;

struct Node
{
	vector<int> Adj;
	int d, f, low, p, Color, n;
}Graph[10001];

bool isArtPoint[10001];

void ClearGraph()
{
	for (int i = 1; i <= N; i++)
	{	
		Graph[i].Adj.clear();
		isArtPoint[i] = 0;
	}
}

void Initialize()
{
	t = 0;
	ans = 0;
	for (int i = 1; i <= N; i++)
	{
		Graph[i].d = Graph[i].f = 0;
		Graph[i].low = INF;
		Graph[i].p = 0;
		Graph[i].Color = -1;
		Graph[i].n = 0;
	}
}

void DFSVisit(int u)
{
	Graph[u].Color = 0;					//u is discovered. paint gray.
	Graph[u].low = Graph[u].d = ++t;	//discovery time and low alloted ++time

	for (int i = 0; i < Graph[u].Adj.size(); i++)	//iterating through neighbours of 'u'
	{
		int v = Graph[u].Adj[i];	//'v' is 'i'th neighbour of 'u'

		if (Graph[v].Color == -1)	//if 'v' is white (undiscovered), we visit it
		{
			Graph[u].n++;			//increase children count of 'u'
			
			Graph[v].p = u;			//assign parent of 'v' as 'u'
			DFSVisit(v);			//DFS over 'v'

			Graph[u].low = min(Graph[u].low, Graph[v].low);

			if (u != 1 && Graph[v].low >= Graph[u].d)	//non-root articulation point condition
			{
				//cout<<"Articulation point found: "<<u<<endl;
				isArtPoint[u] = 1;
			}
		}

		else if (Graph[u].p != v)	//back-edge
		{
			//cout<<"Back edge "<<u<<", "<<v<<endl;
			Graph[u].low = min(Graph[u].low, Graph[v].d);
		}
	}

	if (u == 1 && Graph[u].n >= 2)	//root of Depth-first tree
	{
		//cout<<"Articulation point found: "<<u<<endl;
		isArtPoint[u] = 1;
	}
	
	t++;							
	Graph[u].f = t;					//finishing time
	Graph[u].Color = 1;				//paint 'u' black
}

int DFS()
{
	Initialize();
	for (int i = 1; i <= N; i++)
		if (Graph[i].Color == -1)
			DFSVisit(i);
	for (int i = 1; i <= N; i++)
		if (isArtPoint[i])
			ans++;
	return ans;
}

void AddEdge(int v1, int v2)
{
	Graph[v1].Adj.push_back(v2);
	Graph[v2].Adj.push_back(v1);
}

void ShowPred()
{
	for (int i = 1; i <= N; i++)
		cout<<i<<": Parent in Search tree = "<<Graph[i].p<<endl;
	cout<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int v1, v2;
	while (cin>>N>>M && !(N == 0 &&  M == 0))
	{
		ClearGraph();
		for (int i = 1; i <= M; i++)
		{
			cin>>v1>>v2;
			AddEdge(v1, v2);
		}
		cout<<DFS()<<endl;
		//ShowPred();
	}
	//cout<<"Time elapsed = "<<clock()/(double)CLOCKS_PER_SEC<<endl;
	return 0;
}
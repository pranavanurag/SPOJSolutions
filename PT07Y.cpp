#include <iostream>
#include <vector>
using namespace std;

bool isTree = true;

struct Node
{
	int N;
	bool Visited;
	std::vector<Node*> Neighbours;
	bool Parent;
	Node()
	{
		N = 0;
		Visited = false;
		Parent = false;
	};

	void AddNeighbour(Node &Neighbour)
	{
		Neighbours.push_back(&Neighbour);
		N++;
	}

	void VisitNode()
	{
		Parent = true;
		for(int i = 0; i < N; i++)
			if(!Neighbours[i]->Parent)
				if(!Neighbours[i]->Visited)
					Neighbours[i]->VisitNode();
				else
					isTree = false;
		Parent = false;
		Visited = true;
	}
};

int main()		
{
	ios::sync_with_stdio(false);

	int V, E, v1, v2;
	cin>>V>>E;
	if(V == E+1)
	{
		Node Graph[10000];
		for(int i = 0; i < E; i++)
		{
			cin>>v1>>v2;
			if(v1 != v2)
			{
				Graph[v1-1].AddNeighbour(Graph[v2-1]);
				Graph[v2-1].AddNeighbour(Graph[v1-1]);
			}
			else
			{
				cout<<"NO";
				return 0;
			}
		}

		Graph[0].VisitNode();

		if(isTree)
		{
			for(int i = 0; i < V; i++)
				if(!Graph[i].Visited)
				{
					cout<<"NO";
					return 0;
				}
			cout<<"YES";
		}
		else
			cout<<"NO";

	}
	else
		cout<<"NO";
	return 0;
}
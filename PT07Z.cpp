#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct node
{
	std::vector<int> adj;
	bool Visited, Parent;
	node()
	{
		Visited = false;
		Parent = false;
	}
};

int FarthestNode(int root, node Graph[])
{
	int FN = -1;

	queue<int> toVisit;
	toVisit.push(root);

	while(toVisit.size())
	{
		int x = toVisit.front();
		Graph[x].Parent = 1;
		toVisit.pop();
		for(int i = 0; i < Graph[x].adj.size(); i++)
		{
			int y = Graph[x].adj[i];
			if(!Graph[y].Visited)
			{
				toVisit.push(y);
				FN = y;
			}
		}
		Graph[x].Visited = 1;
		Graph[x].Parent = 0;
	}
	return FN;
}

int main()
{
	int n, v1, v2;
	cin>>n;
	node Graph[n];
	for(int i = 0; i < n-1; i++)
	{
		cin>>v1>>v2;
		Graph[--v1].adj.push_back(--v2);
		Graph[v2].adj.push_back(v1);
	}
	int farthestNode = FarthestNode(0, Graph);

	for(int i = 0; i < n; i++)
		Graph[i].Visited = 0;

	queue<int> toVisit;
	int parentNode[n], farthestNode2 = -1;
	for(int i = 0; i < n; i++) parentNode[i] = -1;
	toVisit.push(farthestNode);
	while(toVisit.size())
	{
		int x = toVisit.front();
		Graph[x].Parent = 1;
		toVisit.pop();
		for(int i = 0; i < Graph[x].adj.size(); i++)
		{
			int y = Graph[x].adj[i];
			if(!Graph[y].Visited)
			{
				toVisit.push(y);
				parentNode[y] = x;
				farthestNode2 = y;
			}
		}
		Graph[x].Visited = 1;
		Graph[x].Parent = 0;
	}
	int longestPath = 0;
	int p = farthestNode2;
	while(parentNode[p] != farthestNode)
	{
		longestPath++;
		p = parentNode[p];
	}
	cout<<longestPath+1<<endl;
	return 0;
}
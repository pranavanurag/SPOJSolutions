#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Map[182][182];

struct couple
{
	int i, j;
	couple(int y, int x)
	{
		i = y;
		j = x;
	}
};

couple MakeCouple(int i, int j)
{
	couple x(i, j);
	return x;
}

void AssignMinDistance(int i, int j, int N, int M)
{
	int distance = 0;
	queue<couple> ToVisit;
	Map[i][j] = 0;
	ToVisit.push(MakeCouple(i, j));	//root of BFS

	while(ToVisit.size())
	{		
		int y = ToVisit.front().i;
		int x = ToVisit.front().j;
		couple Visiting(y, x);	//visit this node's neighbours
		ToVisit.pop();	//remove the first element
		distance = Map[y][x] + 1;	//exploring immediate neighbours

		//We visit a node only if the previously assigned distance is larger than the apparent distance

		if (y != 0 && distance < Map[y-1][x])	//can visit up
		{	
			Map[y-1][x] = distance;
			ToVisit.push(MakeCouple(y-1, x));
		}

		if (y != N-1 && distance < Map[y+1][x])	//can visit down
		{
			Map[y+1][x] = distance;
			ToVisit.push(MakeCouple(y+1, x));
		}

		if (x != 0 && distance < Map[y][x-1])	//can visit left
		{
			Map[y][x-1] = distance;
			ToVisit.push(MakeCouple(y, x-1));
		}

		if (x != M-1 && distance < Map[y][x+1])	//can visit right
		{
			Map[y][x+1] = distance;
			ToVisit.push(MakeCouple(y, x+1));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>N>>M;
		std::vector<couple> Ones;
		char x;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M && cin>>x; j++)
				if (x == '1')
				{
					Map[i][j] = -2000;
					Ones.push_back(MakeCouple(i, j));
				}
				else
					Map[i][j] = 2000;	//shall be overwritten the first time it's accessed in BFS
	
		for (int i = 0; i < Ones.size(); i++)
			AssignMinDistance(Ones[i].i, Ones[i].j, N, M);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cout<<Map[i][j]<<' ';
			cout<<endl;
		}
	}
	return 0;
}

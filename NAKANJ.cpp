#include <iostream>
#include <queue>

using namespace std;

bool Visited[101];
int Level[101];

void Initialize()
{
	for (int i = 1; i <= 100; i++)
	{
		Level[i] = -1;
		Visited[i] = 0;
	}
}

bool isValidPosition(int x)
{
	if (x%10 >= 1 && x%10 <= 8)
	{
		x /= 10;
		if (x >= 1 && x <= 8)
			return true;
		return false;
	}
	return false;
}

int MinMoves(int Start, int End)
{
	queue <int> toExplore;
	toExplore.push(Start);

	Level[Start] = 0;

	while(!toExplore.empty())
	{
		int Now = toExplore.front();
		toExplore.pop();

		Visited[Now] = true;

		int N[] = {Now + 12, Now + 21, Now - 8, Now + 19, Now - 12, Now - 21, Now + 8, Now - 19};

		for (int i = 0; i < 8; i++)
		{
			if (!Visited[N[i]] && isValidPosition(N[i]))
			{	
				toExplore.push(N[i]);
				if (Level[N[i]] == -1)
					Level[N[i]] = Level[Now] + 1;
				else
					Level[N[i]] = min(Level[N[i]], Level[Now] + 1);
			}
		}

		if (Now == End)
			break;
	}
	return Level[End];
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--)
	{
		Initialize();
		string temp1, temp2;
		cin>>temp1>>temp2;
		int Start = 10*(temp1[0] - 'a' + 1) + (temp1[1] - '0'),
			End = 10*(temp2[0] - 'a' + 1) + (temp2[1] - '0');
		cout<<MinMoves(Start, End)<<endl;
	}
	return 0;
}
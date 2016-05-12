#include <iostream>
#include <vector>

using namespace std;

struct couple
{
	int i, j;
	couple(int y, int x)
	{
		i = y;
		j = x;
	}
};

couple make_couple(int i, int j)
{
	couple x(i, j);
	return x;
}

inline int mod(int x)
{
	if (x < 0)
		return -x;
	return x;
}

inline int d(couple p1, couple p2)
{
	return mod(p1.i - p2.i) + mod(p1.j - p2.j);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>N>>M;
		std::vector<couple> Ones;
		bool Map[N][M];
		char x;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M && cin>>x; j++)
				if (x == '1')
				{
					Map[i][j] = 1;
					Ones.push_back(make_couple(i, j));
				}
				else
					Map[i][j] = 0;

		for (int i = 0; i < N; i++)
		{	
			for (int j = 0; j < M; j++)
				if (!Map[i][j])
				{
					int minDistance = 2000;
					for (int x = 0; x < Ones.size(); x++)
						minDistance = min(minDistance, d(Ones[x], make_couple(i, j)));
					cout<<minDistance<<' ';
				}
				else
					cout<<"0 ";
			cout<<endl;
		}
	}	
	return 0;
}

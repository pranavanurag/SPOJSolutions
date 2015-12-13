#include <iostream>

using namespace std;

int main()
{
	int N, Candies[10001], Answer=0;
	float Average, Sum=0;

	cin>>N;
	while(N!=-1)
	{
		
		for(int i=0;i<N;i++)
		{
			cin>>Candies[i];
			Sum+=Candies[i];
		}

		Average=(float)(Sum/N);
		
		if(Average==(int)(Average))
		{
			for(int i=0;i<N;i++)
				if(Candies[i]>Average)
					Answer+=Candies[i]-Average;
			cout<<Answer<<endl;
		}
		else cout<<-1<<endl;

		Sum=0;	
		Answer=0;
		
		cin>>N;
	}
	return 0;
}
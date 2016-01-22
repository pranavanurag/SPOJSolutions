#include <iostream>

using namespace std;

int Stack[1000];
int n;

void PushStack(int x)
{
	n++;
	Stack[n] = x;
}

int main()
{
	int t;
	while(cin>>t && t != 0)
	{
		int	LastTruckPassed = 0, TruckNumber;
		bool CanOrder = true;
		n = -1;		//setting stack to empty status

		for (int i = 0; i < t; ++i)
		{
			cin>>TruckNumber;

			if(TruckNumber == (LastTruckPassed+1))	//truck is in correct order and must pass
				LastTruckPassed = TruckNumber;
			else if(n == -1)
				PushStack(TruckNumber);
			else if(TruckNumber < Stack[n])
				PushStack(TruckNumber);
			else
				CanOrder = false;

			while(Stack[n] == (LastTruckPassed+1))
			{	
				LastTruckPassed = Stack[n];
				n--;
			}
		}

		if(CanOrder)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
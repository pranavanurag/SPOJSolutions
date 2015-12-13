#include <iostream>

using namespace std;

long Need, NumberOfFriends, CollectorsParty[10001];
long long Sum=0;

int Partition(long A[], int Start, int End)
{
	int Pivot = A[End];
	int PartitionIndex = Start;
	for(int i=Start; i<End; i++)
		if(A[i]<=Pivot)
		{
			int temp = A[i];
			A[i] = A[PartitionIndex];
			A[PartitionIndex] = temp;
			PartitionIndex+=1;
		}
	int temp = A[PartitionIndex];
	A[PartitionIndex] = A[End];
	A[End] = temp;

	return PartitionIndex;
}

void QuickSort(long A[], int Start, int End)
{
	if(Start<End)
	{
		int Q = Partition(A, Start, End);
		QuickSort(A, Q+1, End);
		QuickSort(A, Start, Q-1);
	}
}


int main()
{
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
		cin>>Need>>NumberOfFriends;
		for(int i=0;i<NumberOfFriends;i++)
			cin>>CollectorsParty[i];
		
		QuickSort(CollectorsParty, 0, NumberOfFriends-1);
		
		int flag=1;
		
		for(int i=NumberOfFriends-1;i>=0;i--)
		{
			Sum+=CollectorsParty[i];
			if(Sum>=Need)
			{	
				cout<<"Scenario #"<<k+1<<':'<<"\n"<<NumberOfFriends-i;
				flag=0;
				break;
			}	
		}

		if(flag==1) cout<<"Scenario #"<<k+1<<':'<<"\nimpossible";
		if(k<t-1) cout<<endl<<endl;
		Sum=0;
	}
	return 0;
}
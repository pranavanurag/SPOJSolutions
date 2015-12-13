#include <iostream>

using namespace std;

int Partition(int A[], int Start, int End)
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

void QuickSort(int A[], int Start, int End)
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
	int t, n, X[1001], Y[1001];
	long Score=0;

	cin>>t;
	while(t--&&t>=0)
	{
		cin>>n;

		for(int i=0;i<n;i++)
			cin>>X[i];
		for(int i=0;i<n;i++)
			cin>>Y[i];

		QuickSort(X, 0, n-1);
		QuickSort(Y, 0, n-1);

		for(int i=0;i<n;i++)
			Score+=X[i]*Y[i];

		cout<<Score<<endl;

		Score=0;
	}
	return 0;
}
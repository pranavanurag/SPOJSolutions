#include <iostream>

using namespace std;

int IsAmbiguous(long x[], long n)
{
	for(int i=0;i<n;i++)
		if(x[x[i]-1]!=i+1)
			return 0;
	return 1;	
}

int main()
{
	long n;
	long Array[100001];
    cin>>n;
	while(n!=0)
	{
		for(int i=0;i<n;i++)
			cin>>Array[i];

		if(IsAmbiguous(Array, n)) cout<<"ambiguous"<<endl;
		else cout<<"not ambiguous"<<endl;
		
		cin>>n;
	}

	return 0;
}
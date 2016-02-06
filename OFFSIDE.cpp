#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A, D;
	cin>>A>>D;
	while(A != 0 && D != 0)
	{
		int Attackers[A], Defenders[D];

		for(int i = 0; i < A; i++)
			cin>>Attackers[i];
		for(int i = 0; i < D; i++)
			cin>>Defenders[i];

		sort(Attackers, Attackers + A);
		sort(Defenders, Defenders + D);

		if(Attackers[0] < Defenders[1])
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;

		cin>>A>>D;
	}
	return 0;
}

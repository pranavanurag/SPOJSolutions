#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int t;
	int nMechaGodzilla, nGodzilla;
	int MaxMechaGodzilla = 0, MaxGodzilla = 0;

	cin>>t;
	while(t--&&t>=0)
	{
		cin>>nGodzilla;		//number of monsters in Godzilla's army
		cin>>nMechaGodzilla;	//number of monsters in MechaGodzilla's army
		for(int i=0; i < nGodzilla; i++)
		{
			int x;
			cin>>x;	//parsing through Godzilla's army
			if(MaxGodzilla < x)
				MaxGodzilla = x;	//storing strongest monster strength in Godzilla's army
		}
		for(int i=0; i < nMechaGodzilla; i++)
		{
			int x;
			cin>>x;	//parsing through Godzilla's army
			if(MaxMechaGodzilla < x)
				MaxMechaGodzilla = x;	//storing strongest monster strenght in MechaGodzilla's army
		}

		if(MaxGodzilla >= MaxMechaGodzilla)
			cout<<"Godzilla"<<endl;
		else if(MaxMechaGodzilla > MaxGodzilla)
			cout<<"MechaGodzilla"<<endl;

		MaxGodzilla = 0;
		MaxMechaGodzilla = 0;
	}
	return 0;
}
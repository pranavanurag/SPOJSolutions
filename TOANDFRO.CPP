#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
	char EncryptedMessage[200];
	int n;
	do
	{
		cin>>n;
		cin>>EncryptedMessage;

		for(int i=0;i<n;i++)
		{
			for(int j=i;j<strlen(EncryptedMessage);)
			{
				cout<<EncryptedMessage[j];

				if(j%2==i%2||j==i)
					j+=2*n-1-2*i;
				else
					j+=2*i+1;
			}
		}
		cout<<endl;
	}while(n!=0);
}

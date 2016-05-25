/*input
long_and_mnemonic_identifier 
anotherExample 
i 
bad_Style 
i 
N 
NAME 
nAME 
_name 
_n_a_m_e 
name 
n_a_m_e 
n_a_m_e_ 
bad_Style 
baD_style 
bad_sTyle 
bAd_style 
bAd_sTyle 
a___b 
a__ 
__aab
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int Convert(string x)
{
	bool flag1 = false, flag2 = false;

	if (x[0] == '_' || isupper(x[0]) || x[x.size()-1] == '_' || isdigit(x[0]))
	{
		cout<<"Error!"<<endl;
		return -1;
	}

	for (int i = 0; i < x.size(); i++)
		if (flag1 && flag2)
		{
			cout<<"Error!"<<endl;
			return -1;
		}

		else if (x[i] == '_')
		{
			if (x[i+1] == '_' || isupper(x[i+1]))
			{
				cout<<"Error!"<<endl;
				return -1;
			}
			flag1 = true;
			x.erase(i, 1);
			x[i] = (char)((int)x[i] - 32);
		}

		else if (isupper(x[i]))
		{
			flag2 = true;
			x.insert(i, "_");
			x[++i] = (char)((int)x[i] + 32);
		}

	cout<<x<<endl;
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	string x;
	while (cin>>x)
		Convert(x);
	return 0;
}
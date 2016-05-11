#include <iostream>

using namespace std;

long long C(long long n,long long k)
{
    long long ans=1;
    k = min(k, n-k);
    long long j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		long long k, n;
		cin>>k>>n;
		cout<<C(k-1, n-1)<<endl;
	}
	return 0;
}

#include <iostream>
#include <math.h>
using namespace std;

int digits(long int x)	//funtion to return the number of digits of a long int
{
	return (int)(log10(x)+1);
}

long rev(long x)	//funtion to return the reversed number using the digits funtion
{
	long revd=0;
	int n=digits(x);
	for(int i=1;i<=n;i++)	//looping for the number of digits
	{
    	revd+=(x%10)*pow(10,n-i);	//reversing the number
    	x/=10;	//dividing the number by 10
	}
	return revd;
}

int main()
{
	long n1, n2;
	int t;
	
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    cin>>n1>>n2;

    	while(n1%10==0)	//getting rid of trailing zeroes
	    	n1=n1/10;
	    while(n2%10==0)	//getting rid of trailing zeroes
	    	n2=n2/10;
		
    	long ans = rev(rev(n1)+rev(n2));	//putting it all together
    	while(ans%10==0) ans=ans/10;	//removing traling zeroes from answer
    	cout<<ans<<endl;
	}
	return 0;
}
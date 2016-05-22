#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

int x[43460], y[1000001];
unsigned long long int m, n;

void initialize()
{
	for(int i=0;i<43459;i++)
		x[i]=1;

	int prime=2;
	for(int i=0;i<43459;i++)
	{
		if(x[i]==1) prime=i+2;
		for(int j=prime*prime-2;j<43459;j+=prime)
			x[j]=0;
	}
}

void printprimes(unsigned long long int m, unsigned long long int n)
{
	if(m==1) m+=1;

	int n1=n-m+1;
	int prime;
	
	for(int i=0;i<n1;i++)
		y[i]=1;

	for(int i=0;i<sqrt(n)-2;i++)
	{
		if(x[i]==1) prime=i+2;
		
		unsigned long long int begin=prime-(m%prime);
		begin=begin%prime;
		
		for(int j=begin;j<n1;j+=prime)
			if(j+m!=prime)
				y[j]=0;
	}

	for(int i=0;i<n1;i++)
		if(y[i]==1) printf("%lld\n", m+i);
}

int main()
{
    initialize();

    int t;
    scanf("%d", &t);

    for(int i=0;i<t;i++)
    {
    	scanf("%lld%lld", &m, &n);
    	printprimes(m,n);
    }	

    return 0;
}
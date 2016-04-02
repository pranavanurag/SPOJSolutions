/*input
1
1 10
*/

#include <iostream>
#include <math.h>

using namespace std;

int x[43460], y[1000001];	//declaring the seive and the segment array
unsigned long long int m, n;	//declaring the integer variables for the segment

void initialize()	//funtion to prepare the seive by assigning all prime representing indices with a value of 1
{
	for(int i=0;i<43459;i++)	//loop to assign all indices a composite marking
		x[i]=1;

	int prime=2;
	for(int i=0;i<43459;i++)	//loop to create the seive
	{
		if(x[i]==1) prime=i+2; //picking up primes to cross out their multiples

		for(int j=prime*prime-2;j<43459;j+=prime)
			x[j]=0;    //crossing out all the multiples of th prime number picked up in the previous loop
	}
}

void printprimes(unsigned long long int m, unsigned long long int n)	//function to seive out all the primes in the segment [m,n]
{
	if(m==1) m+=1;	//incrementing m to 2 if it is 1 to begin with

	int n1=n-m+1;	//n1 is the size of the segment that we have to work with
	int prime;
	
	for(int i=0;i<n1;i++)	//loop to initialize the segment
		y[i]=1;

	for(int i=0;i<sqrt(n)-2;i++)	//loop to cross out multiples in the segment [m,n] of primes from 2 to square root of n
	{
		if(x[i]==1) prime=i+2;
		
		unsigned long long int begin=prime-(m%prime);	//initializing for the starting point to start crossing out multiples in the segmented of the current prime
		begin=begin%prime;	//to avoid begin attaining the value of prime itself
		
		for(int j=begin;j<n1;j+=prime)    //crossing out all the multiples of prime in the segment [m,n]
			if(j+m!=prime)	//checking if the number being crossed out is not the prime itself
				y[j]=0;
	}

	for(int i=0;i<n1;i++)
		if(y[i]==1) cout<<m+i<<endl;	//printing out all the numbers corressponding to a stored value of 1 (prime)
}

int main()
{
	ios::sync_with_stdio(false);
    initialize();	//the seive is now ready

    int t;
    cin>>t;    //number of test cases

    for(int i=0;i<t;i++)	//loop to run the printprimes function t times
    {
    	cin>>m>>n;
    	printprimes(m,n);	//calling the printprimes(,) function
    }	

    return 0;
}
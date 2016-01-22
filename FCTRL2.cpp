#include <iostream>
#include <math.h>

using namespace std;

int x[300];	//array to store the large factorial

void initialize()	//function to set the array back to the value "1"
{
	for(int i=0;i<300;i++)
		x[i]=0;

	x[0]=1;
}

void printfactorial(int n)	//function that works on the initialized array and calculates n! using long multiplication
{
	int m=1;	//variable to store number of digits in the array

	for(int i=1;i<=n;i++)	//loop to run n times and i stores the value to multiply to the array
	{
		int carry=0;	//variable to hold the carry-over during long multiplication process
		for(int j=0;j<m;j++)	//loop to carry out actual long multiplication
		{
			int product=x[j]*i+carry;	//multiplying the digit at j with i
			x[j]=product%10;	//storing the new digits, after multiplication
			carry=product/10;	//calculating and storing the carry over
		}
		while(carry>0)	//loop to make sure no carry over is left over. This loop makes sure to keep tab of increasing digits 'm'
		{
			x[m]=carry%10;	//storing carry over digit in the next index of the array
			m++;	//incrementing number of digits
			carry/=10;
		}
	}
	for(int i=m-1;i>=0;i--) cout<<x[i];	//printing out the array containing n!
}

int main()
{
	int t, n;
	cin>>t;	//test cases

	for(int i=0;i<t;i++)
	{
		cin>>n;
		initialize();
		printfactorial(n);
		cout<<endl;
	}
	return 0;
}

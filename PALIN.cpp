#include <iostream>
#include <string.h>

using namespace std;

bool IsPalindrome(int Array[], int n)	//function to check if parameter array is a palindrome
{
	for (int i = 0; i < n/2; i++)
		if(Array[i] != Array[n-i-1])
			return 0;
	return 1;	
}


void ShowArray(int Array[], int n)	//function to print out integer array as number
{
	for (int i = 0; i < n; ++i)
		cout<<Array[i];
}


long Convert(int Array[], char Source[])	//function that takes character array and assigns integer array the same big number
{
	int length = strlen(Source);
	for (int i = 0; i < length; i++)
		Array[i] = int(Source[i]) - 48;

	return length;
}


void Mirror(int Array[],int Mirrored[], int n)	//function to mirror an array
{
	for (int i = 0; i < (n/2 + 1); i++)		//first half copied as it is
		Mirrored[i] = Array[i];

	for(int i = (n/2 + 1); i<n; i++)	//second half mirrors the first half of original array
		Mirrored[i] = Array[n-i];
}


bool MirrorGreater(int Array[], int Mirrored[]. int n)	//function to comparee two integer arrays and return if mirroed is greater in value
{
	for (int i = 0; i < n; i++)
		if(Mirrored[i] < Array[i)
			return 0;
	return 1;		
}

void Increment(int Array[], int index)
{
	if(Array[index] < 9) Array[index]++;
	else if(Array[index] == 9)
	{
		Array[index] = 0;
		Increment(Array, index + 1);
		Increment(Array, index - 1);
	}
}

void Increment(int Array[], int index1, int index2)
{

}


void IncrementCenter(int Array[]. int n)
{
	if(n%2 == 0)	//two center elements
	{
		Increment(Array, n/2);
		Increment(Array, n/2+1);

	}
}


void NextPalindrome(int Array[], int n)
{
	int Mirrored[1000001];	//Number's first half will bve mirrored into the second half of this array on the way to finding out palindrome

	long n = Convert(Number, String);	//Convert returns length of array, stored it in n

	Mirror(Number, Mirrored, n);	//Mirrored array contains suspected palindrome
}


int main()
{
	char String[1000001];	//initial declaraction for taking input as String
	int Number[1000001];	//string value will be pushed into this integer array

	cin>>String;	//input

	return 0;
}
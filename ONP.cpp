#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

char Stack[400],String[400];	//Stack stores the operators and String is for inputting the test cases
int n=-1;	//variable to store the size of the stack at any given time. -1 denotes empty.


void PushStack(char c)	//function to push operator or '(' into the Stack on the basis of LIFO. it takes care of the priority of the operators as well
{
	n++;
	Stack[n]=c;
}

void ShowStack()	//function to show the operators for the characters displayed till now
{
	while(Stack[n]!='(')	//stop at the first instance of '(' while moving back from n to 0
	{
		cout<<Stack[n];
		n--;	//decrementing the value of n
	}
	n--;	//decrementing the value of n again so as to delete the '('
}

void EmptyStack()	//function to show the operators left behind
{
	while(n>=0)
	{
		cout<<Stack[n];
		n--;
	}
}

int main()
{
	int t;	//test cases
	cin>>t;

		for(int i=0;i<t;i++)	//loop to run t times
		{
		cin>>String;	//inputting the string

		for(int j=0;j<(int)strlen(String);j++)	//loop to run through the String
		{
			if(isalpha(String[j]))	//if the element in the String is an alphabet, we print it
				cout<<String[j];
			else if(String[j]=='('||String[j]=='+'||String[j]=='^'||String[j]=='/'||String[j]=='*'||String[j]=='-')	//if it is an operator or '(' we push it to the Stack
				PushStack(String[j]);
			else if(String[j]==')') 	//else if it is a ')' we show the stack upto the first instance of '('
				ShowStack();
		}
		EmptyStack();	//emptying the stack to make sure no operators are left behind
		n=-1;	//restoring Stack status to empty
		cout<<endl;
	}
	return 0;
}

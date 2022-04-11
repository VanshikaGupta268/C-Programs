#include<iostream>
using namespace std;
// Stack Creation
char stack[50];
//top declaration;
 int top=-1;
 //declaration of push,pop, isempty,isfull,peek and display functions
void push(char a);
void pop();
bool isempty();
bool isfull(int);
char peek();
void display(int,string);
 int main()
 {
 	string str;
 	int i,length;
 	cout<<"Enter the size of the stack: ";//input size
 	cin>>length;
 	cout<<"Enter the elements of the stack: ";//input elements
 	for(int k=0;k<length;k++)
 	{
 	    cin>>str[k];
 	}
 	for(i=0;i<length;i++)
	 {
		push(str[i]);
		if(str[i]=='*')
		{
			pop();
		}
	
	}
	cout<<"Use of push function\n"<<stack[top];
	cout<<"\n******\n";
	char element;
	element=peek();
	cout<<"Use of peek function\n";
	cout<<element;
	 cout<<"\n*********\n";
	 cout<<"Use of display function\n";
	display(length,str);
	 cout<<"\n*********\n";
	 cout<<"Use of isfull function\n";
	 if(isfull(length))
	 {
	 	cout<<"stack is full";
	 }
	 else
	 {
	 	cout<<"Stack is not full\n";
	 }
	  cout<<"\n*********\n";
	 cout<<"Use of isempty function\n";
	  if(isempty())
	  {
	  	cout<<"The stack is empty";
	  }
	  else
	{
		cout<<"The stack is not empty";
	}
	 return 0;
 	
 }
void display(int length,string str)
{
	for(int m=0;m<length;m++)
	{
		cout<<stack[m];
		cout<<"\n";
	}
}
 void push(char a)
 {
 	top++;
 	stack[top]=a;
 }
 void pop()
 {
 	top--;
 	cout<<"Use of pop function\n"<<stack[top];
 	cout<<"\n******\n";
 }
 char peek()
 {
 	return stack[top];
 }
 bool isempty()
 {
 	if(top==-1)
 	{
 		return true;
	 }
	else
	{
		return false;
	 } 
 }
 bool isfull(int length)
 {
 	if(top==length)
 	{
 		return true;
	 }
	else
	{
		return false;
	 } 
 }


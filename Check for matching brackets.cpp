
#include <iostream>
using namespace std;
// Stack Creation
char stack[50];
//top declaration;
 int top=-1;
 //declaration of push,pop,peek and isempty functions
 void push(char a);
 void pop();
 bool isempty();
 char peek();
 //declaration of the string length function
 int StrLen(string str, int index);
 bool TestForBalancedBrackets(string str);
 int main()
 {
 	string str;
 	cout<<"Enter the string to be checked:\t";
 	cin>>str;
 	if(TestForBalancedBrackets(str)){
 		cout<<"\nYes, the given expression have balanced brackets.";
	 }
	else{
		cout<<"\nNo, the given expression does not have balanced brackets.";
	} 
	return 0 ;
 }
  int StrLen(string str, int index)
{
if (str[index] == '\0') 
return 0;
else
return (1 + StrLen(str, index + 1));
}
//push the charachter into the stack
void push(char a)
{
  	top++;
	stack[top]=a;
}
void pop()
{
    top--;
}
//check if the stack is empty
bool isempty()
{
if(top == -1)
return true;
else
return false;
}
char peek()
{
    return stack[top];
}
bool TestForBalancedBrackets(string str)
{
	int i,length,index=0;
	char x;
	length=StrLen(str,index);
	for(i=0;i<length;i++)
	{
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')
		{
			push(str[i]);
			//keep on pushing the elements in the stack till one of the above 3 brackets are encountered
			continue;
		}
        switch (str[i]) {
        case ')':
             
            // Store the top element in x
            x = peek();
            pop();
            if (x == '{' || x == '[')
                return false;
            break;
 
        case '}':
 
            // Store the top element in x
            x = peek();
            pop();
            if (x == '(' || x == '[')
                return false;
            break;
 
        case ']':
 
            // Store the top element in x
            x = peek();
            pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
		
	}
	return (isempty());
}

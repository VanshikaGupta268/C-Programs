#include<iostream>
using namespace std;
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
//Function to return precedence of operators
int prec(char c) {
	if(c == '^')
		return 3;
	else if(c == '/' || c=='*')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// The main function to convert infix expression
//to postfix expression
void infixToPostfix(string str) {

	//stack<char> st; For stack operations, we are using C++ built in stack
	string result;
    int length,index=0;
    length=StrLen(str,index);
	for(int i = 0; i < length; i++) {
		char c = str[i];

		// If the scanned character is
		// an operand, add it to output string.
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if(c == '(')
			push('(');

		// If the scanned character is an ‘)’,
		// pop and to output string from the stack
		// until an ‘(‘ is encountered.
		else if(c == ')') {
			while(peek() != '(')
			{
				result += peek();
				pop();
			}
			pop();
		}

		//If an operator is scanned
		else {
			while(!isempty() && prec(str[i]) <= prec(peek())) {
				result =result + peek();
				pop();
			}
			push(c);
		}
	}

	// Pop all the remaining elements from the stack
	while(!isempty()) {
		result =result + peek();
		pop();
	}

	cout << result << endl;
}

//Driver program to test above functions
int main() {
	string str ;
	cout<<"Enter the string:\t";
	cin>>str;
	if(TestForBalancedBrackets(str)){
 		infixToPostfix(str);
	 }
	else{
		cout<<"\nThe given expression does not have balanced brackets, hence further conversion is not possible";
	} 
	return 0;
}


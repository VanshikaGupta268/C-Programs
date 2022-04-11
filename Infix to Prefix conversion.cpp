#include<iostream>
//#include<string>
using namespace std;

char stack[50];
int top=-1;
void reverse(string &str);
void push(char ch);
void pop();
char peek();
bool isempty();
void push(char ch){
	top++;
	stack[top]=ch;
}

void pop()
{
    top--;
}

char peek(){
	return stack[top];
}

bool isempty()
{
if(top == -1)
return true;
else
return false;
}

int StrLen(string str, int index)
{
if (str[index] == '\0') 
return 0;
else
return (1 + StrLen(str, index + 1));
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

void reverse(string &str)
{
	int length,index=0;
	
	length=StrLen(str,index);
	
	for(int i=0;i<length;i++)
	{
		char ch=str[i];
		push(ch);
	}
	for (int i = 0; i < length; i++)
    {
        str[i] = peek();
        pop();
    } 
}
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
string infixToPostfix(string str) {

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

	//cout << result << endl;
	return result;
	
}


 
int main()
{
    string str1,str2,str3 ;
    cout<<"Enter the infix expression:\t";
    cin>>str1;
    //reverse(str);
    //cout << str;
	if(TestForBalancedBrackets(str1)){
		reverse(str1);
		//cout<<"hi"<<str1;
		str2=str1;
	
		int length,index=0;
		length=StrLen(str2,index);
		for (int i = 0; i <= length; i++) 
		{	if (str2[i] == '(') {
			str2[i] = ')';
			
		}
		else if (str2[i] == ')') {
			str2[i] = '(';
			
		}
	}
		cout<<str2;
		cout<<"\n";
		//infixToPostfix(str2);
 		str3=infixToPostfix(str2);
 		cout<<str3;
 		cout<<"\n";
 		reverse(str3);
 		cout<<"The final expression is:";
 		cout<<"\n";
 		cout<<str3;
	 }
	else{
		cout<<"\nThe given expression does not have balanced brackets, hence further conversion is not possible";
	} 
 
    return 0;
}

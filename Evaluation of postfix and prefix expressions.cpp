# include <iostream>
# include <cmath>
using namespace std;

int top = -1;
int maxsize = 100;
int stack[100];
char equation[50];
int length = 0;

void push(int value)
{
	if(top==(maxsize-1))
	{
		// overflow - cannot insert value
		cout << "Stack is full - overflow" << endl;
	}
	else
	{
		top++;
		stack[top]=value;
	}
}

int pop()
{
	if(top==-1)
	{
		// underflow - cannot remove value
		cout << "Stack is empty - underflow" << endl;
		return 0;
	}
	else
	{
		int value = stack[top];
		top--;
		return value;
	}
}

bool isOperator(char c)  
{  
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' )  
		return true;
	return false;  
}  

bool isOperand(char c)  
{  
	if(c >= '0' && c <= '9') 
		return true;	
	return false;  
}  

void post_evaluation()
{
	int i, j, op1, op2, ptr = 0, number = 0;
	char word[10];
	
	equation[length] = ' ';
	length++;
	
	for(i=0;i<length;i++)
	{

		if(equation[i]!=' ')
		{
			word[ptr] = equation[i];
			ptr++;

		}
		else
		{
			
			if(ptr==1)
			{
				if(isOperand(word[0]))
				{
					push(word[0]-'0');
				}
				
				else if(isOperator(word[0]))
				{
					
					op2 = pop();
					op1 = pop();
			
					if(word[0]=='+')
						push(op1+op2);
				
					if(word[0]=='-')
						push(op1-op2);
				
					if(word[0]=='*')
						push(op1*op2);
				
					if(word[0]=='/')
						push(op1/op2);
				
					if(word[0]=='^')
						push(pow(op1, op2));
				}
			}
			else
			{
				for(j=0;j<ptr;j++)
				{

					number = number*10 + (word[j]-'0');
				}
				
				push(number);
			}
			
			for(j=0;j<ptr;j++)
			{

				word[j] = '\0';
			}
			number = 0;
			ptr = 0;
			
		}
	}
}

void pre_evaluation()
{
	int i, j, op1, op2, ptr = 0, number = 0;
	char word[10]; char ch;
	
	for(i=length;i>=0;i--)
		equation[i] = equation[i-1];
	
	equation[0] = ' ';
	
	length++;
	
	for(i=length-1;i>=0;i--)
	{

		if(equation[i]!=' ')
		{
			word[ptr] = equation[i];
			ptr++;

		}
		else
		{
			
			if(ptr==1)
			{
				if(isOperand(word[0]))
				{
					push(word[0]-'0');
					

				}
				
				else if(isOperator(word[0]))
				{
					
					op1 = pop();
					op2 = pop();
			
					if(word[0]=='+')
						push(op1+op2);
				
					if(word[0]=='-')
						push(op1-op2);
				
					if(word[0]=='*')
						push(op1*op2);
				
					if(word[0]=='/')
						push(op1/op2);
				
					if(word[0]=='^')
						push(op1^op2);
				}
			}
			else
			{
				for(j=ptr-1;j>=0;j--)
				{

					number = number*10 + (word[j]-'0');
				}
				
				push(number);
			}
			
			for(j=0;j<ptr;j++)
			{

				word[j] = '\0';
			}
			number = 0;
			ptr = 0;
			
		}
	}
}

int main()
{
	int i, option;
	
	cout << "Enter equation: ";
	cin.get(equation, 50);
	
	cout << "Choose:" << endl << "1. Postfix Evaluation" << endl << "2. Prefix Evaluation" << endl << "Enter your choice: " << endl;
	cin >> option;
	
	for(i = 0; equation[i]!='\0'; i++)
		length++;
	
	switch(option)
	{
		case 1:
			post_evaluation();
			break;
			
		case 2:
			pre_evaluation();
			break;
	}
		
	cout << "Evaluation: " << pop() << endl;

	return 0;
}

#include <iostream>
using namespace std;
// Stack Creation
char stack[50];
//top declaration;
 int top=-1;
 //declaration of push,pop and peek functions
 void push(char a);
 void pop();
 int peek();
 //declaration of the string length function
 int StrLen(string str, int index);
 //declaration of the boolean function that return the value "True" if string is a palindrome
 bool PalindromeTestFunction(string s);
//finding the length of the string
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
//pop the charachter out of the stack
void pop()
{
    top--;
}
//to peek the top value of the stack
int peek()
{
return stack[top];
}
//test function
bool PalindromeTestFunction(string str)
{
	int length,index=0;
	length = StrLen(str,index);
    // to Find the mid value of the entered string
    int i, middle;
	middle = length / 2;
 
    for (i = 0; i < middle; i++) 
	{
        push(str[i]);
    }
 
    //now we will check if the entered string has odd number of charachters or even
    //if odd number of charachters then we will neglect the middle value as it will not affect the test for palindrome
  
    if ((length % 2) != 0)
	 {
        i++;
    }
   
    char element_from_stack;
    while (str[i] != '\0')
    {
    	//to store the top value from the stack using the peek function
         element_from_stack = peek();
         //decrement the top operator
         pop();
 //now we will compare the top element of the stack with the element of the string ,to check if they are equal
    if (element_from_stack != str[i])
    //if elements are not equal , then it is not a plaindrome
        return false;
        i++;
    }
//if the above case does not happen, then the string is a palindrome    
return true;
}
int main()
{
    string str ;
    cout<<"Enter the string to be checked:\t";
    cin>>str;
 
    if (PalindromeTestFunction(str)) 
	{
        cout << "\nYes, the entered string is a palindrome";
    }
    else
	 {
        cout << "\nNo, the entered string is not a palindrome";
    }
 
    return 0;
}

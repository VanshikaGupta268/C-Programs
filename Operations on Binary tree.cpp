#include<iostream>
#include <stack>
#include<string.h>
using namespace std;


struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = NULL;
	}
};
struct node
{
	int Data;
	node* Left;
	node* Right;
};
node* Root=NULL;

//insert
void insert()
{
	int ele;
	cout << "Enter value to insert: ";
	cin >> ele;
				
	node* temp;
	node* cur;
	node* prev;
	
	char dir[10];
	int i;
	
	temp = new node();
	temp->Data = ele;
	temp->Left = temp->Right = NULL;
	
	if(Root == NULL)
	{
		Root = temp;
		return;
	}
	
	cout << endl <<"Enter direction (l for left; r for right):";
	cin >> dir;
	prev = NULL;
	cur = Root;
	
	for(i = 0; i < strlen(dir); i++)
	{
		prev = cur;
		
		if(dir[i]=='l')
			cur = cur->Left;
		else
			cur = cur->Right;
	}
	
	if(cur!= NULL||i != strlen(dir))
	{
		cout<<"Invalid Insertion!";
		delete temp;
		return;
	}
	
	if(dir[i-1]=='l')
		prev->Left = temp;
	else
		prev->Right = temp;
	
}


void inorderIterative(Node* root)
{
	stack<Node*> stack;
	Node* curr = root;
	while (!stack.empty() || curr != NULL)
	{
		// if the current node exists, push it into the stack (defer it) and move to its left child
		if (curr != NULL)
		{
			stack.push(curr);
			curr = curr->left;
		}
		else {
			// otherwise, if the current node is null, pop an element from the stack,
			// print it, and finally set the current node to its right child
			curr = stack.top();
			stack.pop();
			cout << curr->data << " ";

			curr = curr->right;
		}
	}
}
// Iterative function to perform postorder traversal on the tree
void postorderIterative(Node* root)
{
	// return if the tree is empty
	if (root == NULL) {
		return;
	}

	// create an empty stack and push the root node
	stack<Node*> s;
	s.push(root);

	// create another stack to store postorder traversal
	stack<int> out;

	// loop till stack is empty
	while (!s.empty())
	{
		// pop a node from the stack and push the data into the output stack
		Node* curr = s.top();
		s.pop();

		out.push(curr->data);

		// push the left and right child of the popped node into the stack
		if (curr->left) {
			s.push(curr->left);
		}

		if (curr->right) {
			s.push(curr->right);
		}
	}

	// print postorder traversal
	while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
}
// Iterative function to perform preorder traversal on the tree
void preorderIterative(Node* root)
{
	// return if the tree is empty
	if (root == NULL) {
		return;
	}

	// create an empty stack and push the root node
	stack<Node*> stack;
	stack.push(root);

	// start from the root node (set current node to the root node)
	Node* curr = root;

	// loop till stack is empty
	while (!stack.empty())
	{
		// if the current node exists, print it and push its right child
		// to the stack before moving to its left child
		if (curr != NULL)
		{
			cout << curr->data << " ";

			if (curr->right) {
				stack.push(curr->right);
			}

			curr = curr->left;
		}
		else {
			curr = stack.top();
			stack.pop();
		}
	}
}

int getLeafCount(Node* node)
{
    if(node == NULL)    
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;        
    else
        return getLeafCount(node->left)+getLeafCount(node->right);
}


int main()
{
	int choice;
	cout<<"Enter your choice: ";
	cout<<"1. Iteratively create a binary tree\n";
 	cout<<"2. In order traversal\n"; 
 	cout<<"3. Post order traversal\n"; 
 	cout<<"4. Preorder traversal\n";
    cout<<"5. Count the number of leaf nodes in a binary tree\n";
    cout<<"6. Exit\n";
	cin>>choice;							
		Node* root = new Node(1);
				root->left = new Node(2);
				root->right = new Node(3);
				root->left->left = new Node(4);
				root->right->left = new Node(5);
				root->right->right = new Node(6);
				root->right->left->left = new Node(7);
				root->right->left->right = new Node(8);
	switch(choice)
	{
		case 1:
			    int Choice;
				   	do{
				    	cout << endl << "Menu - 0: Exit 1: Enter elements" << endl;
				    	cin >> Choice;
				    	
				    	switch(Choice){
				    		case 0:
				    	   		break;	
						   	case 1: 
				    	        insert();
				    	        break;
				       }
				       
				   }while(Choice != 0);
				break;
				
		case 2:
				inorderIterative(root);
				break;
		case 3:
				postorderIterative(root);	
				break;
		case 4:
				preorderIterative(root);
				break;
		case 5:	
				int count = getLeafCount(root);
				cout<<count;
				break;
	}
	return 0;
}

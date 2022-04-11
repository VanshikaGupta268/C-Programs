#include <iostream>
using namespace std;

struct node
{
int data;
struct node* left;
struct node* right;
};

int depth(struct node *root)
{
if(root==NULL)
return 0;
else
return( 1+ max(depth (root->left), depth(root->right)));
}
int max(int a, int b)
{
if(a>b)
return a;
else
return b;
}

bool Find_Parent(struct node *root, int target)
{
    if(root == NULL) 
        return false; 
      
    if(root->data == target)
        return true;
        
    if (Find_Parent(root->left, target) || Find_Parent(root->right, target))
     {
	    cout<<root->data;
        exit(0);
        return true;
 	 }
 	return false; 
}  

bool printAncestors(struct node *root, int target)
{
if (root == NULL)
	return false;

if (root->data == target)
	return true;
if ( printAncestors(root->left, target) ||	printAncestors(root->right, target) )
{
	cout << root->data << " ";
	return true;
}


return false;
}

struct node* newnode(int data)
{
struct node* node = (struct node*)::operator new(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}

int main()
{
int choice;	
int element;
struct node *root = newnode(10);
root->left	 = newnode(11);
root->right	 = newnode(12);
root->left->left = newnode(13);
root->left->right = newnode(14);
root->left->left->left = newnode(15);
cout<<"\n1: Print the parent of the given element";
cout<<"\n2: Print the depth of a tree";
cout<< "\n3: Print the ancestors of a given node";
cout<<"\n4: Exit\n";
cout<<"Enter your choice: ";
cin>>choice;
switch(choice)
{
	case 1:
		cout<<"\nEnter the node to check for the parent: \n";
		cin>>element;
		cout<<"The parent of the entered node is: ";
		Find_Parent(root,element);	
		getchar();
		break;
	case 2:
		cout<<"The depth of the tree is: "<<depth(root);
		break;
	case 3:
		cout<<"\nEnter the node to check for the ancestors: \n";
		cin>>element;	
		cout<<"\nThe ancestors of the entered node are: ";
		printAncestors(root, element);
		getchar();
		break;
	case 4:
		exit(0);						
}
return 0;
}





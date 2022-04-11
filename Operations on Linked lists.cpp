#include<iostream>
using namespace std;

struct node {
	int info;
	struct node* link;
};
struct node* start = NULL;

// Function to traverse the linked list
void traverse()
{
	struct node* temp;

	// List is empty
	if (start == NULL)
		cout<<"\nList is empty\n";

	// Else print the list
	else {
		cout<<"The list is: ";
		temp = start;
		while (temp != NULL) {
			cout<<temp->info<<"\t";	
			temp = temp->link;
		}
		cout<<"\n";
	}
}
// Function to insert at the front of the linked list
void insertAtFront()
{
	int data;
	struct node* temp;
	temp =(struct node*):: operator new(sizeof(struct node));
	printf("\nEnter number to be inserted : ");
	cin>>data;
	temp->info = data;

	// Pointer of temp will be  assigned to start
	temp->link = start;
	start = temp;
}

// Function to insert at the end of the linked list
void insertAtEnd()
{
	int data;
	struct node *temp, *head;
	temp = (struct node*):: operator new(sizeof(struct node));

	// Enter the number
	cout<<"\nEnter number to be inserted : ";
	cin>>data;

	// Changes links
	temp->link = 0;
	temp->info = data;
	head = start;
	while (head->link != NULL) {
		head = head->link;
	}
	head->link = temp;
}
// Function to insert at any specified position in the linked list
void insertAtPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = (struct node*):: operator new(sizeof(struct node));

	// Enter the position and data
	cout<<"\nEnter position and data :";
    cin>>pos;
    cin>>data;

	// Change Links
	temp = start;
	newnode->info = data;
	newnode->link = 0;
	while (i < pos - 1) {
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}
// Function to delete from any specified position from the linked list
void deletePosition()
{
	struct node *temp, *position;
	int i = 1, pos;

	// If Linled list is empty
	if (start == NULL)
		cout<<"\nList is empty\n";

	// if its not empty
	else {
		cout<<"\nEnter index : ";

		// take the position to be deleted
		cin>>pos;
		position = (struct node*):: operator new(sizeof(struct node));
		temp = start;

		// Traverse till position
		while (i < pos - 1) {
			temp = temp->link;
			i++;
		}

		// Change Links
		position = temp->link;
		temp->link = position->link;

		// Free memory
		//free(position);
		position=NULL;
	}
}

int main()
{
	int choice;
	do {

		cout<<"Enter 1: Display the list\n";
		cout<<"Enter 2: For insertion at starting\n";
		cout<<"Enter 3: For insertion at end\n";
		cout<<"Enter 4: For insertion at any position\n";
		cout<<"Enter 5: For deletion of element at any position\n";
		cout<<"Enter 6: To exit\n";
		cout<<"\nEnter Choice :\n";
		cin>>choice;

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deletePosition();
			break;
		case 6:
			exit(0);
			break;
		default:
			cout<<"Incorrect Choice\n";
		}
	}while(choice!=6);
	return 0;
}


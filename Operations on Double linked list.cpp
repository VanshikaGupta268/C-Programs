#include <iostream>
using namespace std;

class node {
public:
	node* next;
	node* prev;
	int data;
};
void insert_front(node** head)
{
	cout << "\nEnter Data for New Node:";
	node* new_node = new node;
	cin >> new_node->data;
	if (*head == NULL) {
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
	}
	else {
		new_node->next = *head;
		new_node->prev = (*head)->prev;
		((*head)->prev)->next = new_node;
		(*head)->prev = new_node;
		*head = new_node;
	}
}
void insert_end(node** head)
{
	cout << "\nEnter Data for New Node:";
	node* new_node = new node;
	cin >> new_node->data;
	if (*head == NULL) {
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
	}
	else {

		node* curr = *head;
		while (curr->next != *head)
			curr = curr->next;
		new_node->next = curr->next;
		new_node->prev = curr;
		(curr->next)->prev = new_node;
		curr->next = new_node;
	}
}
void insert_after(node** head)
{
	node* new_node = new node;
	cout << "\nEnter Data for New Node:";
	cin >> new_node->data;
	if (*head == NULL) {
		cout << "\nThere is No element in the List";
		cout << "\nCreating a new node";
		new_node->prev = new_node;
		new_node->next = new_node;
		*head = new_node;
	}
	else {
		int num;
		cout << "Enter After Element:";
		cin >> num;
		node* curr = *head;
		while (curr->data != num) {
			curr = curr->next;
			if (curr == *head) {

				cout << "\nEntered Element"
					<< " Not Found in "
						"List\n";
				return;
			}
		}
		new_node->next = curr->next;
		new_node->prev = curr;
		(curr->next)->prev = new_node;
		curr->next = new_node;
	}
}
void insert_before(node** head)
{
	node* new_node = new node;

	if (*head == NULL) {
		cout << "List is Empty";
		cout << "\nEnter Data for New Node:";
		cin >> new_node->data;
		new_node->prev = new_node;
		new_node->next = new_node;
		*head = new_node;
	}

	else {
		int num;
		cout << "\nEnter Before Element:";
		cin >> num;
		if ((*head)->data == num)
			insert_front(head);

		else {
			node* curr = (*head)->next;

			while (curr->data != num) {
				if (curr == *head) {
					cout << "\nEntered Element Not Found "
							"in List!!\n";
					return;
				}
				curr = curr->next;
			}

			cout << "\nEnter Data For New Node:";
			cin >> new_node->data;
			new_node->next = curr;
			new_node->prev = curr->prev;
			(curr->prev)->next = new_node;
			curr->prev = new_node;
		}
	}
}
void delete_end(node** head)
{
	if (*head == NULL) {
		cout << "\nList is Empty!!\n";
	}
	else if ((*head)->next == *head) {
		delete *head;
		*head = NULL;
	}
	else {
		node* curr = new node;
		curr = *head;
		while (curr->next != (*head)) {
			curr = curr->next;
		}
		(curr->prev)->next = curr->next;
		(curr->next)->prev = curr->prev;
		delete curr;
	}
}
void search(node* head)
{
	if (head == NULL) {
		cout << "List is empty!!";
		return;
	}

	int item;
	cout << "Enter item to be searched:";
	cin >> item;
	node* curr = head;
	int index = 0, count = 0;
	do {

		if (curr->data == item) {
			cout << "\nItem found at position:"
				<< index + 1;
			count++;
		}
		index++;
		curr = curr->next;
	} while (curr != head);
	if (count == 0)
		cout << "Item searched not found in list";
}
void delete_front(node** head)
{
	if (*head == NULL) {
		cout << "\nList in empty!!\n";
	}
	else if ((*head)->next == *head) {
		delete *head;
		*head = NULL;
	}
	else {
		node* curr = new node;
		curr = (*head)->next;
		curr->prev = (*head)->prev;
		((*head)->prev)->next = curr;
		delete *head;
		*head = curr;
	}
}
void delete_mid(node** head)
{
	if (*head == NULL) 
	{
		cout << "\nList is Empty!!!";
	}

	else {
		cout << "\nEnter Element to be deleted:";
		int num;
		cin >> num;
		if ((*head)->data == num) {
			delete_front(head);
		}

		else {
			node* curr = (*head)->next;
			while ((curr->data) != num) {
				if (curr == (*head)) {
					cout << "\nEntered Element Not Found "
							"in List!!\n";
					return;
				}
				curr = curr->next;
			}
			(curr->prev)->next = curr->next;
			(curr->next)->prev = curr->prev;
			delete curr;
		}
	}
}



void display(node* head)
{
	node* curr = head;
	if (curr == NULL)
		cout << "\n List is Empty!!";
	else {
		do {
			cout << curr->data << ",";
			curr = curr->next;
		} while (curr != head);
	}
}

void display_menu()
{
	cout << "1. Insert At End\n";
	cout << "2. Insert After Element\n";
	cout << "3. Insert Before Element\n";
	cout << "4. Delete From End\n";
	cout << "5. Delete At A Position\n";
	cout << "6.Exit";
}

int main()
{
	int choice;
	node* head = NULL;
	display_menu();
	do {
		cout << "\nEnter Your Choice:";
		cin >> choice;
		switch (choice) {
		case 1: {
			insert_end(&head);
			display(head);
			break;
		}
		case 2: {
			insert_after(&head);
			display(head);
			break;
		}
		case 3: {
			insert_before(&head);
			display(head);
			break;
		}
		case 4: {
			delete_end(&head);
			display(head);
			break;
		}
		case 5: {
			delete_mid(&head);
			display(head);
			break;
		}
		case 6:
			exit(0);
		default: {
			cout << "\nInvalid Input";
			display_menu();
			break;
		}
		}

	} while (choice!=6);
	return 0;
}


#include<iostream>
using namespace std;
string queue[3];
int front = -1;int rear=-1;int n=3;

void enqueue() {
	string element;
    cout<<"Enter the element: ";
	cin>>element;
   if ((front == 0 && rear == n-1) || (front == rear+1)) {
      cout<<"Queue Overflow \n";
      return;
   }
   if (front == -1) {
      front = 0;
      rear = 0;
   } else {
      if (rear == n - 1)
      rear = 0;
      else
      rear = rear + 1;
   }
   queue[rear] = element ;
}
void dequeue() {
   if (front == -1) {
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<queue[front]<<endl;

   if (front == rear) {
      front = -1;
      rear = -1;
   } else {
      if (front == n - 1)
      front = 0;
      else
      front = front + 1;
   }
}

void display() {
   int f = front, r = rear;
   if (front == -1) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are :\n";
   if (f <= r) {
      while (f <= r){
         cout<<queue[f]<<" ";
         f++;
      }
   } else {
      while (f <= n - 1) {
         cout<<queue[f]<<" ";
         f++;
      }
      f = 0;
      while (f <= r) {
         cout<<queue[f]<<" ";
         f++;
      }
   }
   cout<<endl;
}

int main(){
	
	int choice = 1;
	while(choice != 0)   
    {     
        cout<<"\nMenu options:  1. Enqueue  2. Dequeue  3. Display 4.Exit\n";  
        cout<<"Enter option from 0 to 3: ";  
    	cin>>choice;
    	
        switch(choice)
        {
        	
			case 1:
        		enqueue();
        		break;
        	case 2:
			    dequeue();
				break;	
			case 3:
				display();
				break;
			case 4:
				exit(0);
        		break;	
			default:
				cout<<"invalid Choice, please enter again!";
		}
	}

	return 0;
}

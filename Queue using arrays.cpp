#include <iostream>
using namespace std;
#define maxsize 3
void Enqueue();  
void Dequeue();  
void display();  
void size();
void IsEmpty();
void Front();
int front = -1, rear = -1;  
int queue[maxsize];  
int main ()  
{  
    int choice;   
    while(choice != 5)   
    {     
        cout<<"\n*************************Select your choice*****************************\n";  
        cout<<"\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Size\n5.Check for Empty";
        cout<< "\n6.Front value\n7.Exit\n";  
        cout<<"\nEnter your choice\n";  
        cin>>choice;  
        switch(choice)  
        {  
            case 1:  
            Enqueue();  
            break;  
            case 2:  
            Dequeue();  
            break;  
            case 3:  
            display();  
            break;
            case 4:
            size();
            break;  
            case 5:
            IsEmpty();
            break;
            case 6:
            Front();
            case 7:  
            exit(0);  
            break;  
            default:   
            cout<<"\nEnter valid choice\n";  
        }  
    }  
    return 0;
}  
void Enqueue()  
{  
    int item;  
    cout<<"\nEnter the element\n";  
    cin>>item;      
    if(rear == maxsize-1)  
    {  
       cout<<"\nOVERFLOW\n";  
         return;  
    }  
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    queue[rear] = item;  
    cout<<"\nValue inserted ";  
      
}  
void Dequeue()  
{  
    int item;   
    if (front == -1 || front > rear)  
    {  
        cout<<"\nUNDERFLOW\n";  
        return;  
              
    }  
    else  
    {  
        item = queue[front];  
        if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else   
        {  
            front = front + 1;  
        }  
        cout<<"\nvalue deleted ";  
    }  
      
      
}  
      
void display()  
{  
    int i;  
    if(rear == -1)  
    {  
        cout<<"\nEmpty queue\n";  
    }  
    else  
    {   cout<<"\nprinting values .....\n";  
        for(i=front;i<=rear;i++)  
        {  
            cout<<queue[i];  
            cout<<","; 
        }     
    }  
}  

void size()
{
    cout<<"Size of the queue:\t";
    int size=(rear-front);
    cout<<size;
}

void IsEmpty()
{
    if(rear==front)
    {
        cout<<"Yes the queue is empty";
    }
    else
    {
        cout<<"No the queue is not empty";
    }
}

void Front()
{
    cout<<queue[front];
}

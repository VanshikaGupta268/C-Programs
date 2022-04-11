#include<iostream>
using namespace std;

void swapping(int &x, int &y)
{     
   int temp;
   temp = x;
   x = y;
   y = temp;
}

void display(int *arr, int size) 
{
   for(int i = 0; i<size; i++)
      cout << arr[i] << "\n";
   cout << endl;
}

void Bubble_sort(int *arr,int size)
{
	int i=0;
	int j;
	int flag=0;
	while(i<=size-1 && flag==0)
	{
		j=size-1;
		flag=1;
		while(j>i)
		{
			if(arr[j]<arr[j-1])
			{
				flag=0;
				swapping(arr[j],arr[j-1]);
			}
		j--;	
		}
	i++;	
	}
}


int main() 
{
   int size;
   cout << "Enter the size of the array: ";
   cin >> size;
   int arr[size];       
   cout << "Enter the elements:" << endl;
   for(int i = 0; i<size; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, size);
   
   Bubble_sort(arr,size);
   cout << "Array after Sorting: ";
   display(arr, size);
   return 0;
}

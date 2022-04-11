#include <iostream>
using namespace std;

void Insertion_Sorting(int arr[], int n)
{
	int temp, j;
	for (int i = 1; i < n; i++)
	{
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

void display(int *arr, int size) 
{
   for(int i = 0; i<size; i++)
      cout << arr[i] << "\n";
   cout << endl;
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
   
   	int n = sizeof(arr) / sizeof(arr[0]);
	Insertion_Sorting(arr, n);
	cout << "Array after Sorting: ";
   display(arr, size);
	
    return 0;
}



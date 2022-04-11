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

void  Selection_Sorting(int *arr, int size) 
{
   int idx_min;
   for(int i = 0; i<size-1; i++) 
   {
      idx_min = i;  
      for(int j = i+1; j<size; j++)
         if(arr[j] < arr[idx_min])
            idx_min = j;
    	swapping(arr[i], arr[idx_min]);
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
   
   Selection_Sorting(arr, size);
   cout << "Array after Sorting: ";
   display(arr, size);
   return 0;
}

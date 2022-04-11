#include <iostream>
using namespace std;

void swapping(int* x, int* y)
{     
   	int temp = *x;
	*x = *y;
	*y = temp;
}
int partition(int *arr,int Low,int High)
{
	int pivot,i,j;
	pivot=arr[Low];
	i=Low+1;
	j=High;
	while(i<High && pivot>=arr[i])
	{
		i++;
	}	
	while(pivot<arr[j])
	{
		j--;
	}	
	if(i<j)	
	{
		swapping(&arr[i],&arr[j]);
	}
	else
	{
		swapping(&arr[Low],&arr[j]);
	}
	return j;
}
void Quick_sort(int *arr,int low,int high)
{
//	int mid;
	if(low<high)
	{
	int mid = partition(arr,low,high);
		Quick_sort(arr,low,mid-1);
		Quick_sort(arr,mid+1,high);
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
	//int n = sizeof(arr)/sizeof(arr[0]);
   Quick_sort(arr,0,size-1);
   cout << "Array after Sorting: ";
   display(arr, size);
   return 0;
}



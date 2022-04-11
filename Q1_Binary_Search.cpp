#include <iostream>
using namespace std;

int Binary_Search(int arr[], int Left, int Right, int search_element)
{
	if (Right >= Left)
	{
		int middle = Left + (Right - Left) / 2;
		
		if (arr[middle] == search_element)
			return middle;

		if (arr[middle] > search_element)
			return Binary_Search(arr, Left, middle - 1, search_element);

		return Binary_Search(arr, middle + 1, Right, search_element);
	}
    else
    {
	return -1;
    }
}
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
	int arr[10];
    int element,size=0;
    cout<<"Enter the size of the array: ";
    cin>>size;
    cout<<"Enter the array: ";
    for(int i=0 ;i<size ;i++)
    {
        cin>>element;
      arr[i]=element;
    } 
    //using Selection sort first to sort the array
   Selection_Sorting(arr, size);
   cout << "Array after Sorting: ";
   display(arr, size);
   //now search for the element int the sorted array
	int search_element;
	cout<<"Enter the element to be searched: ";
	cin>>search_element;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = Binary_Search(arr, 0, n-1 , search_element);
	(result == -1)? cout << "Element is not present in array": cout << "Element is present at index " << result;
	return 0;
}


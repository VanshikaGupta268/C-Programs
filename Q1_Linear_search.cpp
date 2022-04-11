#include <iostream>
using namespace std;

int search(int arr[], int num, int search_element)
{
	for (int i = 0; i < num; i++)
		if (arr[i] == search_element)
			return i;
	return -1;
}

// Driver code
int main(void)
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
	int search_element;
	cout<<"Enter the element to be searched: ";
	cin>>search_element;
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	int result = search(arr, n, search_element);
	(result == -1)? cout << "Element is not present in array": cout << "Element is present at index " << result;
	return 0;
}


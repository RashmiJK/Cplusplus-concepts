#include <iostream>

using namespace std;

int binarySearch(int arr[], int item, int low, int high)
{
    if (high <= low)
        return (item > arr[low]) ? (low+1) : low;
    
    int mid = (low + high)/2;
    
    if (item == arr[mid])
        return mid+1;

    if(item > arr[mid])
        return binarySearch(arr, item, mid+1, high) ;
        
    return binarySearch(arr, item, low, mid-1);   
}

void BinaryInsertionSort(int arr[],int n)
{
    int i, j, selected, loc, k;

    for(i = 1; i < n; i++ )
    {
        j = i - 1; 
        selected = arr[i];
        loc = binarySearch(arr, selected, 0, j);
        while( j >= loc)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = selected;

        cout << "Intermediate result : \n" << endl;
        for(k = 0; k < n; k++)
            cout << arr[k] << "\t";
        cout << endl;
    }
}
int main()
{
    int arr[] = {12, 56, 1, 67, 45, 8, 82, 16, 63, 23};

    int n = sizeof(arr)/sizeof(arr[0]);
    int i;

    BinaryInsertionSort(arr,n);

    cout << "Sorted array is : \n" << endl;
    for(i = 0; i < n; i++)
        cout << arr[i] << "\t";

    cout << endl;
    return 0;
}
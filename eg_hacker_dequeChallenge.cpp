#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> q;
    int max = 0;
    int indexOfMax = 0;
    
    for(int i = 0; i<=(n-k) ; i++)
    {  
        if(i == 0 || (indexOfMax < i || indexOfMax > (i+k))) // first window
        {    
            max = 0;      
            for(int j = i; j<(i+k); j++ )
            {
                if(arr[j] > max)
                {
                    max = arr[j];
                    indexOfMax = j;            
                }
            }
            q.push_back(max);
        }
        else // following windows, compare max to (i+k-1) index content only
        {
            if(arr[i+k-1] > max)
            {
                q.push_back(arr[i+k-1]);
                max = arr[i+k-1];
                indexOfMax = i+k-1;
            }
            else
            {
                q.push_back(max);
            }
        }            
    }
    //cout << " Size = " << q.size() << endl;
    for(auto p : q)
        cout << p << " ";
    cout << endl;    
}
int main()
{
  
    int arr[] = {3, 4, 6, 3, 4};
   	printKMax(arr, sizeof(arr)/sizeof(int), 2);
  	return 0;
}
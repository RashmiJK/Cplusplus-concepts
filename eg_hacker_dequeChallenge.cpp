/* Given a set of arrays of size  and an integer , you have to find the maximum integer for each and every contiguous subarray of size  for each of the given arrays.

Input Format

First line of input will contain the number of test cases T. For each test case, you will be given the size of array N and the size of subarray to be used K. This will be followed by the elements of the array Ai.

Constraints



 , where  is the  element in the array .

Output Format

For each of the contiguous subarrays of size  of each array, you have to print the maximum integer.

Sample Input

2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10
Sample Output

4 6 6 4
8 8 8 10
Explanation

For the first case, the contiguous subarrays of size 2 are {3,4},{4,6},{6,3} and {3,4}. The 4 maximum elements of subarray of size 2 are: 4 6 6 4.

For the second case,the contiguous subarrays of size 4 are {3,4,5,8},{4,5,8,1},{5,8,1,4} and {8,1,4,10}. The 4 maximum element of subarray of size 4 are: 8 8 8 10.

Language
C++14

More
123456789101112131415161718192021222324
    	t--;
  	}
  	return 0;
}
Line: 24 Col: 2

Submit Code

Run Code

Upload Code as File

Test against custom input
Contest CalendarBlogScoringEnvironmentFAQAbout UsSupportCareersTerms Of ServicePrivacy PolicyRequest a Feature
 */

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
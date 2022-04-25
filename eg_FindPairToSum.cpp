/* 
    Find a pair of numbers in an array that adds to a given sum
    int arr[] = {2, 4, 7}
    int sum = 9
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int arr[] = {2, 4, 5 ,7};
    int sum = 9;
    int arrSize = (sizeof(arr)/sizeof(int)) - 1;
    int i = 0;
    int addend1 = arr[i];

    cout << "Size of input array = " << arrSize << endl;

    while(i <= arrSize && addend1 < sum)
    {
        int j = i + 1;

        while (j <= arrSize && (sum-addend1) >= arr[j])
        {
            if(addend1 + arr[j] == sum)
            {
                cout << addend1 << " + " << arr[j]  << " = " << sum << endl;
                j = arrSize + 1;
            }
            else
            {                
                cout << addend1 << " + " << arr[j] << " != " << sum << endl;                
                j++;
            }
        }
        i++;
        addend1 = arr[i];
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string binarySearch(vector<int> ar, int num)
{
    int first = 0;
    int last = ar.size() - 1;
    string Isfound = "NO";

    while(first <= last)
    {
        int mid = (first + last) / 2;
        if( num == ar[mid])
        {
            Isfound = "YES";
            break;
        }    
        else if( num > ar[mid])
            first = mid + 1;
        else
            last = mid - 1;
    }
    return Isfound;
}

int main()
{
    vector<int> arr = { 2, 3, 4, 10, 40 };
    int x = 11;

    cout << binarySearch(arr, x) << endl;
    bool found = std::binary_search(arr.begin(), arr.end(), x);
    cout << ((found)?"YES\n":"NO\n") << endl;


    return(0);
}
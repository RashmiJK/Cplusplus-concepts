/*
Given an array, reduce the array to a single element with minimum cost. For reducing, remove two elements from the array, add those two numbers and keep the sum back in the array. The cost of each operation is the sum of the elements removed in that step.

Example, let the array A = [1,2,3]

Then, we can remove 1 and 2, add both of them and keep the sum back in array. Cost of this step would be (1+2) = 3.

So A = [3,3], Cost = 3

In second step, we can remove both elements from the array and keep the sum back in array again. Cost of this step would be 3 + 3 = 6.

So, A = [6], Cost = 6

So total cost turns out to be 9 (6+3).

*/

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int arr[] = {5, 5, 5, 5};
    multiset<int> my_set;
    int cost = 0;

    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
        my_set.insert(arr[i]);

    for(auto x : my_set)
        cout << x << " ";
    cout << endl;

    while(my_set.size() > 1)
    {
        auto it = my_set.begin();
        auto prev_it = it;
        int temp = 0;

        temp = *it + *(++it);
        my_set.insert(temp);
        cost += temp;
        my_set.erase(prev_it);
        my_set.erase(it);

        for(auto x : my_set)
            cout << x << " ";
        cout << endl;

    }

    cout << "cost = " << cost << endl;

    return 0;
}
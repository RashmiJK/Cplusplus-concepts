/* The frequency sort algorithm is used to output elements of an array in descending order of their frequencies.
 * If two elements have the same frequencies, then the element that occurs first in the input is printed first.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool cmp(vector<int>a, vector<int> b)
{
    if(a[0] > b[0]) return true;
    if(a[0] == b[0])
    {
        return a[2] < b[2];
    }
    return false;
}

vector<int> frequencySort(vector<int>& in_arr)
{
    unordered_map<int,vector<int>> hash; // {frequency, index}
    
    for(size_t i = 0; i < in_arr.size(); i++)
    {
        if(hash.find(in_arr[i]) == hash.end()) // new key
        {
            hash[in_arr[i]] = {1, static_cast<int>(i)};
        }
        else
        {
            // key alreay exists
            hash[in_arr[i]][0] += 1;
        }        
    }
    cout << "key" << " : " << "frequency" << " : " << "first found index" << endl;
    for(auto x : hash)
        cout << x.first << " : " << x.second[0] << " : " << x.second[1] << endl;
    
    cout << endl;

    /* transfer to vector of vectors in the order {frequency, key, first found index} */
    vector<vector<int>> v;
    for(auto a: hash)
        v.push_back({a.second[0], a.first, a.second[1]});
    for(auto p: v)
    {
        for(auto q: p)
            cout << q << " ";
        cout << endl;
    }

    sort(v.begin(), v.end(), cmp);
    cout << "after calling sort : " << endl;
    for(auto p: v)
    {
        for(auto q: p)
            cout << q << " ";
        cout << endl;
    }

    vector<int> ans;
    for(auto a:v)
    {
        int x = a[0]; //frequency
        while(x--)
        {
            ans.push_back(a[1]);
        }
    }
    return(ans);
}

int main()
{
    vector<int> nums = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
    vector<int> ans = frequencySort(nums);

    for(auto m : ans)
        cout << m << "  ";
    cout << endl;
    return 0;
}
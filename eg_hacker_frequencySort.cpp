/* Given an array of integer nums, sort the array in increasing order based on the frequency of the values. 
 * If multiple values have the same frequency, sort them in decreasing order. 
 */
#include <iostream>
#include <unordered_map>
#include <iterator>
#include <vector>
#include <map>

using namespace std;
class Solution
{
    public:
        vector<int>frequencySort(vector<int>&);
        static bool cmp(vector<int>a, vector<int>b);
};

bool Solution::cmp(vector<int>a, vector<int>b)
{
    if(a[0] < b[0]) return true;
    if(a[0] == b[0])
    {
        return a[1] > b[1];
    }
    return false;
}

vector<int> Solution::frequencySort(vector<int>& input_arr) // reference to vector to avoid copying
{
    unordered_map<int,int> hash_value_to_freq;
    for(auto ele : input_arr) hash_value_to_freq[ele]++;

    cout << "unordered_map : " << endl;
    cout << "value : occurances" << endl;
    for(auto x:hash_value_to_freq)
        cout << x.first << " : " << x.second << endl;

    /* Transfer the contents of unordered_map into 2 dimensional vector
     * so that, sort can be used
     */
    vector<vector<int>> v;
    for(auto a: hash_value_to_freq)
    {
        v.push_back({a.second, a.first});
    }

    cout << "Contents of 2 dimesional vector (occurances : value ) " << endl;
    for(auto t: v)
    {
        for(auto p: t)
            cout << p << " ";
        cout << endl;
    }    

    sort(v.begin(), v.end(), cmp);
    cout << "after calling sort : " << endl;
    for(auto t: v)
    {
        for(auto p: t)
            cout << p << " ";
        cout << endl;
    }    

    vector<int> ans;
    for(auto a:v)
    {
        int x = a[0];
        while(x--)
        {
            ans.push_back(a[1]);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
    Solution s;
    vector<int> ans = s.frequencySort(nums);
    for(auto m : ans)
        cout << m << " ";
    return 0;
}